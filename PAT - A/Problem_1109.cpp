#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)

typedef long long LL;

#define MAXN 120000

struct Obj{
    string name;
    int height,id,order;
    bool operator <(const Obj& A) const{
        return height == A.height? name > A.name : height < A.height; ///error
    }
}stu[MAXN];
bool MyCmp(const Obj& A, const Obj& B){
    return A.order < B.order;
}
void Print(int lef,int rig){ // [lef,rig)
    int sign = 1, id = 0;
    Fde(i,rig-1,lef){
        stu[i].order = sign * id;
        sign = -sign;
        ++id;
    }
    sort(stu+lef,stu+rig,MyCmp);
    Fin(i,lef,rig-1){
        char letter = i == rig-1? '\n':' ';
        cout << stu[i].name << letter;
    }
}
int main()
{
    //freopen("e:\\test.txt","r",stdin);
    int N,K;
    while(~scanf("%d %d",&N,&K)){
        Fin(i,0,N-1){
            cin >> stu[i].name >> stu[i].height;
        }
        sort(stu,stu+N);
        int width = N / K;
        int r = N % width;
        while(N){
            Print(max(N - width - r,0) ,N);
            N -= width + r;
            r = 0;
        }
        /*
        int r = N%K, q = N/K;
        Print(max(N-r-K,0),N); ///error
        N = K * (q-1);
        while(N > 0){
            Print(N-K,N); ///error
            N -= K;
        }
        */
    }
    return 0;
}
/*
175 188 190 186
168 170 168
160 160 159
*/
