#include <bits/stdc++.h>
using namespace std;
#define Fin(i,f,t) for(int i=f;i<=t;++i)

typedef long long LL;

#define MAXN 220

bool mat[MAXN][MAXN];
int nv,ne,m,k;
int s[MAXN];

bool Judge(){
//     Fin(i,1,nv) Fin(j,1,nv)
//            printf("%d%c",mat[i][j],j==nv?'\n':' ');
    Fin(i,0,k-1)
        Fin(j,i+1,k-1)
            if(!mat[s[i]][s[j]]){
                //printf("%d ! %d\n",s[i],s[j]);
                return false;
            }

    return true;
}

bool JudgeEx(int u){
    Fin(i,0,k-1)
        if(!mat[u][s[i]])
            return false;
    return true;
}


void Handle(){

    scanf("%d",&k);
    Fin(i,0,k-1){
        scanf("%d",&s[i]);
    }
    bool flag = Judge();
    if(!flag){
        printf("Not a Clique\n");
        return;
    }
    flag = false;
    Fin(i,1,nv)if(JudgeEx(i)){
        flag = true;
        break;
    }
    printf("%s\n",flag?"Not Maximal":"Yes");
}
int main(){
    while(~scanf("%d %d",&nv,&ne)){
        memset(mat,false,sizeof mat);
        int f,t;
        Fin(i,1,ne){
            scanf("%d %d",&f,&t);
            mat[f][t] = mat[t][f] = true;
        }

        scanf("%d",&m);
        Fin(i,1,m){
            Handle();
        }
    }
    return 0;
}
