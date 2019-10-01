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

#define MAXN 160
#define NIL -1
struct Node {
	int lson, rson, v;
	void Init() {
		SfI2(lson, rson);
	}
}node[MAXN];

int N, inOrder[MAXN], pos;
void Create(int u) {
	if (u == NIL)
		return;
	Create(node[u].lson);
	node[u].v = inOrder[pos++];
	Create(node[u].rson);
}
void Init() {
	Fin(i, 0, N - 1)
		node[i].Init();
	Fin(i, 0, N - 1)
		SfI(inOrder[i]);
	sort(inOrder, inOrder + N);
	pos = 0;
	Create(0);
}
void Level() {
	queue<int> Q;
	Q.push(0);
	int x;
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		if (~node[x].lson) Q.push(node[x].lson);
		if (~node[x].rson) Q.push(node[x].rson);
		printf("%d%c", node[x].v, !Q.empty() ? ' ' : '\n');
	}
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		Level();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


// - 17.32
