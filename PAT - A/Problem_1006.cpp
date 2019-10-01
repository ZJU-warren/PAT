#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)

typedef long long LL;

#define MAXN 120000

struct Rec{
    string id,in,out;
    void Scan(){
        cin>>id>>in>>out;
    }
}r[MAXN];

int main()
{
    int M;
    while(~SfI(M)){
        Fin(i,0,M-1)
            r[i].Scan();
        Fin(i,1,M-1) if(r[i].in < r[0].in)
            swap(r[i],r[0]);
        cout << r[0].id << ' ';
        Fin(i,1,M-1) if(r[i].out > r[0].out)
            swap(r[i],r[0]);
        cout << r[0].id << endl;
    }
    return 0;
}
