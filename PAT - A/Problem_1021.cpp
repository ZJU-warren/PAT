#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <climits>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfD(x) scanf("%lf",&x)
#define SfLL(x) scanf("%lld",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 105000
#define NIL -1
#define INF	0x3f3f3f3f

int par[MAXN];
void SetInit(int N) {
	Fin(i, 1, N)
		par[i] = i;
}
int Find(int x) {
	return par[x] = x == par[x]? x : Find(par[x]);
}
void Unite(int x, int y) {
	x = Find(x);
	y = Find(y);
	par[y] = x;
}
struct V {
	int first;
}vex[MAXN];
struct E {
	int t, next;
}edge[MAXN * 2];
int cntE;
void AddEdge(int f, int t) {
	edge[cntE].t = t;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}
int N;
int CalField() {
	int cnt = 0;
	Fin(i, 1, N) {
		Find(i);	// 更新
		if (par[i] == i)
			++cnt;
	}
	return cnt;
}
void Init() {
	SetInit(N);
	Fin(i, 1, N)
		vex[i].first = NIL;
	int f, t;
	Fin(i, 1, N - 1) {
		SfI2(f, t);
		AddEdge(f, t);
		AddEdge(t, f);
		Unite(f, t);
	}
}
int cntS, resEnds[MAXN];
bool roots[MAXN];
int d[MAXN];
int FindLongest(int u) {
	memset(d, 0x3f, sizeof d);
	queue<int> Q;
	d[u] = 0;
	Q.push(u);
	int maxLen = -1;
	while (!Q.empty()) {
		u = Q.front();
		maxLen = max(maxLen, d[u]);
		//printf("u == %d\n", u);
		Q.pop();
		for (int i = vex[u].first; ~i; i = edge[i].next) if (d[edge[i].t] == INF){
			d[edge[i].t] = d[u] + 1;
			//printf("push -- %d, %d\n", edge[i].t, d[edge[i].t]);
			Q.push(edge[i].t);
		}
	}
	//printf("maxLen = %d\n", maxLen);
	Fin(i, 1, N) if (d[i] == maxLen) {
		//printf("that is %d\n", i);
		roots[i] = true;
	}
	//printf("_____________\n");
	return maxLen;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	int res;
	while (~SfI(N)) {
		Init();
		res = CalField();
		if (res > 1) {
			printf("Error: %d components\n", res);
			continue;
		}
		memset(resEnds, false, sizeof resEnds);
		cntS = 0;
		int maxLen = FindLongest(1);
		Fin(i, 1, N) if (d[i] == maxLen)
			resEnds[cntS++] = i;
		Fin(i, 0, cntS - 1) {
			maxLen = FindLongest(resEnds[i]);
		}
		Fin(i, 1, N) if (roots[i])
			printf("%d\n", i);

	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
