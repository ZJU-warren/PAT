#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define MAXN 52000


struct Node{
    int lef,rig;
    int v;
    Node(){lef = rig = v = 0;}
}node[MAXN];

int arrPre[MAXN],arrIn[MAXN],len;
bool flag;

void Post(int root){
    if(!root)
        return;
    if(flag) return;
    Post(node[root].lef);
    if(flag) return;
    Post(node[root].rig);
    if(flag) return;
    printf("%d\n",node[root].v);
    flag = true;
}

int insure;
void Create(int l,int r,int &par){

    if(l > r)
        return;
/** cache insure because of its change in next deep **/
    int now = ++insure;
    node[now].v = arrPre[now];
    par = now;
    int id = l;
    for(;arrIn[id] != arrPre[now]; ++id);
    //printf("id = %d\n",id);
    Create(l,id-1,node[now].lef);
    Create(id+1,r,node[now].rig);
}

int main(void){
    while(~scanf("%d",&len)){
        Fin(i,1,len)
            scanf("%d",&arrPre[i]);
         Fin(i,1,len)
            scanf("%d",&arrIn[i]);
        insure = 0;
        Create(1,len,node[0].lef);
        flag = false;
        Post(node[0].lef);
    }
}
