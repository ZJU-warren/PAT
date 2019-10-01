#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)

typedef long long LL;

#define MAXN 1200
#define EXP 1e-5

double arr[MAXN];
int N;
void Scan(){
    int id;
    double t;
    Fin(i,1,N){
        SfI(id);
        SfD(t);
        arr[id] += t;
    }
}
void Print(){
    int cnt = 0;
    Fde(i,MAXN-1,0) if(fabs(arr[i]) > EXP)
        ++cnt;
    printf("%d",cnt);
    Fde(i,MAXN-1,0) if(fabs(arr[i]) > EXP)
        printf(" %d %.1lf",i,arr[i]);
    putchar('\n');
}
int main()
{
    while(~SfI(N)){
        Fin(i,0,MAXN-1)
            arr[i] = 0;
        Scan();
        SfI(N);
        Scan();
        Print();

    }
    return 0;
}
