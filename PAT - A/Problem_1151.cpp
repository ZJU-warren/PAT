#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <cstdlib>
#include <climits>
#include <stack>
#include <algorithm>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x, y) scanf("%d%d",&x, &y)
#define SfI3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 100550
#define NIL -1
struct Node{
	int lson, rson, v, per;
	void Init(int tv, int tper){
		lson = rson = NIL;
		v = tv, per = tper;
	}
}node[MAXN];
map<int, int> Map;
int cntNode;
int M, N;
int preOrder[MAXN], inOrder[MAXN], pos;
void Create(int L, int R, int & per, int perId){
	if(L > R)
		return;
	int mid = L;
	for(;mid <= R && inOrder[mid] != preOrder[pos];mid++);
	per = ++cntNode;
	Map[preOrder[pos]] = cntNode;
	node[per].Init(preOrder[pos++],perId);
	Create(L, mid-1,node[per].lson,per);
	Create(mid+1,R,node[per].rson,per);
}
void Init(){
	Map.clear();
	cntNode = 1;
	Fin(i,1,N)
		SfI(inOrder[i]);
	Fin(i,1,N)
		SfI(preOrder[i]);
	pos = 1;
	Create(1,N,node[0].lson,0);
}

bool Exist(int a,int b){
	int ra = Map[a], rb = Map[b];
	if(ra && rb) return true;
	if(!ra && !rb)
		printf("ERROR: %d and %d are not found.\n", a, b);
	else if(!ra)
		printf("ERROR: %d is not found.\n", a);
	else if(!rb)
		printf("ERROR: %d is not found.\n", b);
	return false;
}
bool path[MAXN];
void Handle(int a, int b){
	memset(path,false,sizeof path);
	if(!Exist(a,b))
		return;
	if(a == b){
		printf("%d is an ancestor of %d.\n",a,b);
	return;
	}

	int par = Map[a];
	while(par){
		path[par] = true;	
		//printf("%d ",node[par].v);
		par = node[par].per;
	}//putchar('\n');
	par = Map[b];
	while(!path[par]){
		//printf("%d ",node[par].v);
		par = node[par].per;
	}//putchar('\n');
	if(node[par].v == a)
		printf("%d is an ancestor of %d.\n",a,b);
	else if(node[par].v == b)
		printf("%d is an ancestor of %d.\n",b,a);
	else
		printf("LCA of %d and %d is %d.\n", a,b,node[par].v);
}
int main(void){
#ifdef DEBUG
	freopen("d:\\test.txt","r",stdin);
	freopen("d:\\tsst.txt","w",stdout);
#endif
	SfI(M);
	  if(SfI(N) == -1) while(1);
		Init();
		int a,b;
		Fin(i,1,M){
			SfI2(a,b);
			Handle(a,b);
		}

#ifdef DEBUG
	//while(1);
#endif
	return 0;
}
