#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)

typedef long long LL;

#define MAXN 100
char None[MAXN];
int N;

struct Node{
    string str;
    int lef,rig;
}node[MAXN];

bool id[MAXN];
int Scan(){
    memset(id,false,sizeof id);
    Fin(i,1,N){
        cin >> node[i].str;
        scanf("%d %d",&node[i].lef,&node[i].rig);
        id[node[i].lef] = id[node[i].rig] = true;
    }
    Fin(i,1,N) if(!id[i])
        return i;
    return -1;
}
void Dfs(int i){
    //printf("_____%d____\n",i);
    bool flag;
    if(~node[i].lef){
        flag = ~node[node[i].lef].lef || ~node[node[i].lef].rig;
        if(flag)    putchar('(');
        Dfs(node[i].lef);
        if(flag)    putchar(')');
    }
    cout<<node[i].str;
    if(~node[i].rig){
        flag = ~node[node[i].rig].lef || ~node[node[i].rig].rig;
        if(flag)    putchar('(');
        Dfs(node[i].rig);
        if(flag)    putchar(')');
    }
}
int main()
{
    //freopen("e:\\test.txt","r",stdin);
    while(~SfI(N)){
        int root = Scan();
        if(!(~root)){
            int x = 0;
            x = 1 / x;
        }
        Dfs(root);
        putchar('\n');
    }
    return 0;
}
