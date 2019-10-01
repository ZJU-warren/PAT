#include <bits/stdc++.h>
using namespace std;
#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
typedef long long LL;

#define MAXN 300500

struct V{
    int first;
}vex[MAXN];

struct E{
    int t,next,fri;
}edge[MAXN];

int cntE;
void AddEdge(int f,int t,bool flag){
    edge[cntE].next = vex[f].first;
    edge[cntE].t = t;
    edge[cntE].fri = flag? 1 : -1;
    vex[f].first = cntE++;
}

int N,M;
bool exist[MAXN];
bool Judge(){
    int Nv,elem;
    scanf("%d",&Nv);
    memset(exist,false,sizeof exist);
    int now = cntE;
    Fin(nv,1,Nv){
        SfI(elem);
        for(int i = vex[elem].first; ~i; i = edge[i].next){
            if(!exist[i]){
                exist[i] = true;
                exist[i+edge[i].fri] = true;
                now -= 2;
            }
        }
        if(!now){
            Fin(lef,nv+1,Nv)
                SfI(elem);
            return true;
        }

    }
    return false;
}
int main()
{
    int f,t;
    while(~scanf("%d %d",&N,&M)){
        /// Init!!!
        cntE = 0;
        Fin(i,0,N-1)
            vex[i].first = -1;
        Fin(i,1,M){
            scanf("%d %d",&f,&t);
            AddEdge(f,t,true);
            AddEdge(t,f,false);
        }
        int k;
        scanf("%d",&k);
        Fin(i,1,k)
            printf("%s\n",Judge()?"Yes":"No");
    }
    return 0;
}
