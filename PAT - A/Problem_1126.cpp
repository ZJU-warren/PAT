#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)

#define MAXN 1000

int N,M;
int par[MAXN];
void Init(){
    Fin(i,1,N)
        par[i] = -1;
}
int Find(int x){
    return ~par[x]? (par[x] = Find(par[x])) : x;
}
void Unite(int x,int y){
    x = Find(x);
    y = Find(y);
    if(x!=y) ///error
        par[y] = x;
}
bool IsLink(){
    int cnt = 0;

    Fin(i,1,N)
        if(Find(i) && !(~par[i]))
            ++cnt;
    return cnt == 1;
}
int d[MAXN];
bool EulerCir(){
    Fin(i,1,N)
        if(d[i]%2)
            return false;
    return true;
}
bool EulerPath(){
    int cnt = 0;
    Fin(i,1,N)
        if(d[i]%2)
            ++cnt;
    return cnt == 2;
}

int main(){
    //freopen("e:\\test.txt","r",stdin);
    while(~scanf("%d %d",&N,&M)){
        int f,t;
        memset(d,0,sizeof d);
        Init();
        Fin(i,1,M){
            scanf("%d %d",&f,&t);
            ++d[f]; ++d[t];
            Unite(f,t);
        }
        Fin(i,1,N)
            printf("%d%c",d[i],i!=N?' ':'\n');
        if(!IsLink())
            printf("Non-Eulerian\n");
        else if(EulerCir())
            printf("Eulerian\n");
        else if(EulerPath())
            printf("Semi-Eulerian\n");
        else
            printf("Non-Eulerian\n");

    }
    return 0;
}
