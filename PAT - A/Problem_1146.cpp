#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

#define MAXN_V 10050
#define MAXN_E 100050

#define NIL -1
struct V{
    int first,id;
}vex[MAXN_V];

struct E{
    int t,next;
}edge[MAXN_E];

int cntE;
void AddEdge(int f,int t){
    edge[cntE].t = t;
    edge[cntE].next = vex[f].first;
    vex[f].first = cntE++;
    ++vex[t].id;
}

int N,M,K;
int notTop[120],cntNot;

void Init(){
    Fin(i,1,N){
        vex[i].first = NIL;
        vex[i].id = 0;
    }
    cntE = cntNot = 0;
}

int tmpId[MAXN_V];
bool Judge(){
    Fin(i,1,N)
        tmpId[i] = vex[i].id;
    int u;
    bool flag = true;
    Fin(i,1,N){
        SfI(u);
        if(tmpId[u] != 0)
            flag = false;
        else{//
            for(int v = vex[u].first; ~v; v = edge[v].next)
                --tmpId[edge[v].t];
        }
    }
    //printf("%d\n",flag);
    return flag;
}
int main()
{
    //freopen("e:\\test.txt","r",stdin);
    int f,t;
    while(~SfI2(N,M)){
        Init();
        Fin(i,1,M){
            SfI2(f,t);
            AddEdge(f,t);
        }
        SfI(K);
        Fin(i,0,K-1)  if(!Judge())
            notTop[++cntNot] = i;
        Fin(i,1,cntNot)
            printf("%d%c",notTop[i],i!=cntNot?' ':'\n');
    }
    return 0;
}
/// 22.54 out

