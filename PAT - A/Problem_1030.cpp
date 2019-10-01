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

#define MAXN 550
#define NIL -1
struct V {
	int first, par, d, c;
}vex[MAXN];
struct E {
	int t, next, d, c;
}edge[MAXN * MAXN];
int cntE = 0;
void AddEdge(int f, int t, int d, int c) {
	edge[cntE].t = t;
	edge[cntE].d = d;
	edge[cntE].c = c;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}
int N, M, S, D;
void Init() {
	Fin(i, 0, N - 1)
		vex[i].par = vex[i].first = NIL;
	int f, t, d, c;
	Fin(i, 1, M) {
		SfI2(f, t);
		SfI2(d, c);
		AddEdge(f, t, d, c);
		AddEdge(t, f, d, c);
	}
}
bool visit[MAXN];
int d[MAXN], c[MAXN];
struct Obj {
	int d, c, vexId;
	Obj(){}
	Obj(int i, int d, int c) :vexId(i), d(d), c(c){}
	bool operator<(const Obj &A) const {
		if (d != A.d)
			return d > A.d;
		return c > A.c;
	}
};
priority_queue<Obj> Q;
void Dij() {
	while (!Q.empty())
		Q.pop();
	Fin(i, 0, N - 1) {
		d[i] = c[i] = INT_MAX;
		visit[i] = false;
	}
	d[S] = c[S] = 0;
	Q.push(Obj(S, 0, 0));
	int u, v;
	while (!Q.empty()) {
		u = Q.top().vexId;
		Q.pop();
		if (visit[u])
			continue;
		if (u == D)
			break;
		visit[u] = true;
		for (int i = vex[u].first; ~i; i = edge[i].next){
			E & e = edge[i];
			v = e.t;
			if (visit[v])
				continue;
			if (d[v] > d[u] + edge[i].d) {
				d[v] = d[u] + edge[i].d;
				c[v] = c[u] + edge[i].c;
				vex[v].par = u;
				Q.push(Obj(v, d[v], c[v]));
			}
			else if (d[v] == d[u] + edge[i].d && c[v] > c[u] + edge[i].c) {
				c[v] = c[u] + edge[i].c;
				vex[v].par = u;
				Q.push(Obj(v, d[v], c[v]));
			}
		}
	}
}
void Print(int u) {
	if (u != S)
		Print(vex[u].par);
	printf("%d ", u);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, M)) {
		SfI2(S, D);
		Init();
		Dij();
		Print(D);
		printf("%d %d\n", d[D], c[D]);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
