#include <bits/stdc++.h>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfLL(x) scanf("%lld",&x)
typedef long long LL;

#define MAXN 140000
#define NIL -1

struct Node{
    int lson, rson, v, per;
    Node() { lson = rson = NIL; }
    void Init(int tv, int tper){
        lson = rson = NIL;
        per = tper;
        v = tv;
    }
}node[MAXN];

map<int, int> Map;
int cntNode;
int inOrder[MAXN], preOrder[MAXN], pos;
/*
void Create(int L, int R, int &per, int id){
    if(L > R)   return;
    int mid = L;
    for(; mid <= R && inOrder[mid] != preOrder[pos]; ++mid);
    per = ++cntNode;
    Map[preOrder[pos]] = cntNode;
    node[per].Init(preOrder[pos++], id);
    Create(L, mid - 1, node[per].lson, per);
    Create(mid + 1, R, node[per].rson, per);
}
*/
void Create(int L, int R, int l, int r, int &per, int id) {
    // cout << "L = " << L << " R = " <<  R << endl;
    if(L > R || l > r) return ;
    int mid = l;
    while(inOrder[mid] != preOrder[L]) mid++;
    per = ++cntNode; Map[preOrder[L]] = cntNode;
    node[per].Init(preOrder[L], id);
    int sz = mid - l;
    Create(L + 1, L + sz, l, mid - 1, node[per].lson, per);
    Create(L + sz + 1, R, mid + 1, r, node[per].rson, per);
}

int N, M;
void Init(){
    Fin(i,1,N)
        SfI(inOrder[i]);
    Fin(i,1,N)
        SfI(preOrder[i]);
    cntNode = 0, pos = 1;
    Map.clear();
    // cout << "(((" << endl;
    Create(1,N,1,N,node[0].lson, 0);
    // cout << "))" <<endl;
}

int a, b;
bool Judge(){
    if(Map.count(a) && Map.count(b)) return true;
    if(!Map.count(a) && !Map.count(b))
        printf("ERROR: %d and %d are not found.\n", a, b);
    else if(!Map.count(a))
        printf("ERROR: %d is not found.\n", a);
    else
        printf("ERROR: %d is not found.\n", b);
    return false;
}
bool path[MAXN];
void Handle(){
    SfI2(a, b);
    if(!Judge()) return;
    memset(path,false,sizeof path);
    int per = Map[a];
    while(per) path[per] = true, per = node[per].per;
    per = Map[b];
    while(!path[per]) per = node[per].per;
    if(per != Map[a] && per != Map[b])
        printf("LCA of %d and %d is %d.\n",a,b,node[per].v);
    else if(per == Map[a])
        printf("%d is an ancestor of %d.\n",a,b);
    else
        printf("%d is an ancestor of %d.\n",b,a);
}

int main()
{
    while(~SfI2(M, N)){
        Init();
        Fin(i,1,M)
            Handle();
    }
    return 0;
}

