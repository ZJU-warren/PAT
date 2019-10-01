#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG 

#define MAXN 10000
#define NIL 0

struct Node {
	int lson, rson, v, Lblack, Rblack;
	void Init(int tv) {
		lson = rson = NIL;
		Lblack = Rblack = 0;
		v = tv;
	}
}node[MAXN];
int preOrder[MAXN], pos, inOrder[MAXN], cntNode;
bool isBRT;
void Create(int L, int R, int &per) {
	if (L > R)
		return;
	int mid = L;
	for (; mid <= R && abs(inOrder[mid]) != abs(preOrder[pos]); ++mid);
	if (mid > R) {
		isBRT = false;
		return;
	}
	per = ++cntNode;
	node[per].Init(preOrder[pos++]);
	Create(L, mid - 1, node[per].lson);
	Create(mid + 1, R, node[per].rson);
}
int N;
bool MyCmp(const int a, const int b) {
	return abs(a) < abs(b);
}
int & treeRoot = node[0].lson;
void Init() {
	Fin(i, 0, N - 1)
		SfI(preOrder[i]), inOrder[i] = preOrder[i];
	sort(inOrder, inOrder + N, MyCmp);
	isBRT = true;
	pos = cntNode = 0;
	Create(0, N - 1, treeRoot);
#ifdef DEBUG
	Fin(i, 1, cntNode)
		printf("node[%d] = %d, lef = %d, rig = %d\n", i, abs(node[i].v), node[i].lson, node[i].rson);
#endif // DEBUG
}
int Dfs(int root) {
	if (node[root].lson == NIL)
		node[root].Lblack = 1;
	else {
		if (node[root].v < 0 && node[node[root].lson].v < 0)
			isBRT = false;
		node[root].Lblack = Dfs(node[root].lson);
	}
	if (node[root].rson == NIL) 
		node[root].Rblack = 1;
	else {
		if (node[root].v < 0 && node[node[root].rson].v < 0)
			isBRT = false;
		node[root].Rblack = Dfs(node[root].rson);
	}
	if(node[root].Lblack != node[root].Rblack)
		isBRT = false;
	//printf("node : %d, L = %d, R = %d\n", node[root].v, node[root].Lblack, node[root].Rblack);
	return node[root].Lblack + (node[root].v > 0);
}
bool Judge() {
	if (!isBRT) return false;
	if (node[treeRoot].v < 0) return false;
	Dfs(treeRoot);
	return isBRT;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	int T;
	while (~SfI(T)) {
		Fin(t, 1, T) {
			SfI(N);
			Init();
			puts(Judge() ? "Yes" : "No");
		}
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


//

