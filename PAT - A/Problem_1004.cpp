#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
#define SfI3(x,y,z) scanf("%d%d%d",&x,&y,&z)
typedef long long LL;

//#define DEBUG

#define MAXN 150
#define NIL	-1

struct V {
	int first;
}vex[MAXN];
struct E {
	int t, next;
}edge[MAXN];
int cntE;
void AddEdge(int f, int t) {
	edge[cntE].t = t;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}

int N, M;
void Init() {
	cntE = 0;
	Fin(i, 0, MAXN - 1)
		vex[i].first = NIL;
	int K, u, v;
	Fin(i, 1, M) {
		SfI2(u, K);
		Fin(k, 1, K) {
			SfI(v);
			AddEdge(u, v);
		}
	}
}
int dg[MAXN], res[MAXN];
void Bfs() {
	memset(dg, 0, sizeof dg);
	memset(res, 0, sizeof res);
	dg[1] = 1;
	queue<int> Q;
	Q.push(1);
	int u, maxDeep = -1;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		maxDeep = max(maxDeep, dg[u]);
		if (vex[u].first == NIL) {
			++res[dg[u]];
			continue;
		}
		for (int i = vex[u].first; ~i; i = edge[i].next) {
			dg[edge[i].t] = dg[u] + 1;
			Q.push(edge[i].t);
		}
	}
	Fin(i, 1, maxDeep)
		printf("%d%c", res[i], i != maxDeep ? ' ' : '\n');
}
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~SfI2(N, M)) {
		Init();
		Bfs();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
