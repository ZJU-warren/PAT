#include <bits/stdc++.h>
using namespace std;
#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
typedef long long LL;

#define MAXN 105000

struct Obj{
    int v,next,id;
}ori[MAXN],tran[3][MAXN];
int num[3];

map<int,int> E;
map<int,int> D;
int first,N,K;

void Handle(){
    int i = first;
    while(~i){
        i = E[i];
        if(ori[i].v < 0)
            tran[0][num[0]++] = ori[i];
        else if(ori[i].v <= K)
            tran[1][num[1]++] = ori[i];
        else
            tran[2][num[2]++] = ori[i];
        i = ori[i].next;
    }
}
void Print(){
    tran[0][num[0]].id = num[1]? tran[1][0].id : tran[2][0].id ;
    tran[1][num[1]].id = tran[2][0].id;
    tran[2][num[2]].id = -1;
    int cnt = num[0] + num[1] + num[2];
    Fin(k,0,2){
        Fin(i,0,num[k]-1){
            if(--cnt)
                /// err 1 : digits five and should switch to display for the address = -1
                printf("%05d %d %05d\n",D[tran[k][i].id],tran[k][i].v,D[tran[k][i+1].id]);
            else{
                printf("%05d %d -1\n",D[tran[k][i].id],tran[k][i].v);
                break;
            }
        }
    }
}
int main()//
{
    while(~scanf("%d %d %d",&first,&N,&K)){
        E.clear();
        D.clear();
        num[0] = num[1] = num[2] = 0;
        int addr;
        Fin(i,0,N-1){
            scanf("%d %d %d",&addr,&ori[i].v,&ori[i].next);
            E[addr] = ori[i].id = i;
            D[i] = addr;
        }
        Handle();
        Print();
    }
    return 0;
}
