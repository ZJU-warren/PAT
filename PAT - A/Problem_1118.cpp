#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)

#define MAXN 10000


int par[MAXN+20],N;
void Init(){
    Fin(i,1,MAXN)
        par[i] = i;
}
int Find(int x){
    return par[x] = (par[x] == x)? x : Find(par[x]);
}
void Unite(int x,int y){
    x = Find(x);
    y = Find(y);
    par[y] = x;
}

int main()
{
    int K,f,t,maxId;
    while(~SfI(N)){
        maxId = 0;
        Init(); /// init
        Fin(i,1,N){
            SfI(K);
            SfI(f);
            maxId = max(maxId,f);
            Fin(k,2,K){
                SfI(t);
                Unite(f,t);
                maxId = max(maxId,t);
            }
        }
        int cnt = 0;
        Fin(i,1,maxId) if(par[i] == i)
            ++cnt;
        printf("%d %d\n",cnt,maxId);
        SfI(K);
        Fin(i,1,K){
            scanf("%d %d",&f,&t);
            printf("%s\n",Find(f) == Find(t)?"Yes":"No");
        }
    }
    return 0;
}
