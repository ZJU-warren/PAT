#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)

#define MAXN 250

bool mat[MAXN][MAXN];
bool visited[MAXN];
int N,M;
bool Judge(){
    memset(visited,false,sizeof visited);
    int len,trash,f,t,beg,fin;
    bool flag = true;
    SfI(len);
    if(len){
        SfI(beg);
        visited[f = beg] = true;
    }
    if(len != N+1)
        flag = false;
    Fin(i,2,len-1){
        if(!flag) ///error for signal
            SfI(trash);
        else{
            //printf("[][][]\n");
            SfI(t);
            if(!mat[f][t] || visited[t])
                flag = false;
            visited[f = t] = true;
        }
    }
    SfI(fin);
    return flag && mat[f][fin] && fin == beg;
}
int main()
{
    int f,t,K;
    while(~scanf("%d %d",&N,&M)){
        memset(mat,false,sizeof mat);
        Fin(i,1,M){
            scanf("%d %d",&f,&t);
            mat[f][t] = true;
            mat[t][f] = true; /// error for not double
        }
        SfI(K);
        Fin(i,1,K)
            printf("%s\n",Judge()?"YES":"NO");
    }
    return 0;
}
