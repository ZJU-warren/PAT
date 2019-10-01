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
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG 

#define MAXN 50
#define NIL -1

int postOrder[MAXN], inOrder[MAXN], N;
struct Node {
	int lson, rson, v;
	void Init(int tv) {
		lson = rson = NIL;
		v = tv;
	}
}node[MAXN];
int pos, cntNode;
void Create(int L, int R, int & per) {
	if (L > R)
		return;
	int mid;
	for (mid = R; mid >= L && inOrder[mid] != postOrder[pos]; --mid);
	per = ++cntNode;
	node[per].Init(postOrder[pos--]);
	Create(mid + 1, R, node[per].rson);
	Create(L, mid - 1, node[per].lson);
}
void Init() {
	Fin(i, 0, N - 1)
		SfI(postOrder[i]);
	Fin(i, 0, N - 1)
		SfI(inOrder[i]);
}
void Level() {
	queue<int> Q;
	Q.push(node[0].lson);
	int x;
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		if (~node[x].lson)
			Q.push(node[x].lson);
		if (~node[x].rson)
			Q.push(node[x].rson);
		printf("%d%c", node[x].v, Q.empty() ? '\n' : ' ');
	}
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)){
		Init();
		pos = N - 1, cntNode = 0;
		Create(0, N - 1, node[0].lson);
		Level();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


// 17.02 - 17.13
