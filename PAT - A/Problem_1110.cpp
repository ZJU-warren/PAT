#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)

typedef long long LL;

#define MAXN 1200
#define NIL -1

struct Obj{
    int far,lchild,rchild;
    void Init(){
        far = lchild = rchild = NIL;
    }
}node[MAXN];

char str[MAXN];
void SetValue(int& x){
    SfS(str);
    if(!strcmp(str,"-"))
        x = NIL;
    else
        sscanf(str,"%d",&x);
}
bool SetFather(int i,int far){
    if(~node[i].far)
        return false;
    node[i].far = far;
    return true;
}
bool flag;
void AddOneNode(int i){
    SetValue(node[i].lchild);
    SetValue(node[i].rchild);
    //printf("_add %d__________________\n",i);
    if(~node[i].lchild)
        flag &= SetFather(node[i].lchild,i);
    //printf("flag = %d\n",flag);
    if(~node[i].rchild)
    flag &= SetFather(node[i].rchild,i);
    //printf("flag = %d\n",flag);
}

int N,root,lastNode;
bool isEnd;
queue<int> Q;
bool Insert(int x){
    if(~x){
        if(isEnd)
            return false;
        else
            Q.push(x);
    }
    else
        isEnd = true;
    return true;
}
void Bfs(int u){
    while(!Q.empty())
        Q.pop();
    isEnd = false;
    Q.push(u);
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        lastNode = u;
        flag &= Insert(node[u].lchild);
        flag &= Insert(node[u].rchild);
        if(!flag){
            break;
        }
    }
}
void Init(){
    Fin(i,0,N-1)
        node[i].Init();
}
int main()
{
    //freopen("e:\\test.txt","r",stdin);
    while(~SfI(N)){
        flag = true;
        Init();
        Fin(i,0,N-1)
            AddOneNode(i);
        root = NIL;
        lastNode = NIL;
        Fin(i,0,N-1)
            if(!(~node[i].far))
                root = i;
        if(flag)
            Bfs(root);
        if(!flag){
            printf("NO %d\n",root);
        }
        else{
            Bfs(root);
            printf("YES %d\n",lastNode);
        }
    }
    return 0;
}
