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
#define SfI3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SfD(x) scanf("%lf",&x)
#define SfLL(x) scanf("%lld",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 550
#define NIL -1
#define INF 0x3f3f3f3f

struct V {
	int c, first;
}vex[MAXN];
struct E {
	int t, len, next;
}edge[MAXN*MAXN];
int cntE;
void AddEdge(int f, int t,int d) {
	edge[cntE].t = t;
	edge[cntE].len = d;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}
int CMAX, N, S, T, M;
void Init() {
	cntE = 0;
	Fin(i, 0, N)
		vex[i].first = NIL;
	Fin(i, 1, N)
		SfI(vex[i].c);
	int f, t, len;
	Fin(i, 1, M) {
		SfI3(f, t, len);
		//printf("-- %d %d %d\n", f, t, len);
		AddEdge(f, t, len);
		AddEdge(t, f, len);
	}
}
int d[MAXN];
bool visit[MAXN];
struct Point {
	int id, d;
	Point(int id, int d):id(id),d(d){}
	bool operator<(const Point &A)const {
		return d > A.d;
	}
};
priority_queue<Point> Q;
void Dij() {
	memset(d, 0x3f, sizeof d);
	memset(visit, false, sizeof visit);
	while (!Q.empty()) Q.pop();
	d[S] = 0;
	Q.push(Point(S, d[S]));
	int u, v;
	while (!Q.empty()) {
		u = Q.top().id;
		Q.pop();
		if (visit[u])
			continue;
		visit[u] = true;
		for (int i = vex[u].first; ~i; i = edge[i].next) {
			v = edge[i].t;
			if (visit[v])
				continue;
			if (d[v] > d[u] + edge[i].len) {
				d[v] = d[u] + edge[i].len;
				Q.push(Point(v, d[v]));
			}
		}
	}
}
int path[MAXN], tempPath[MAXN], cntP;
int minLef, minBring;
void Dfs(int u, int dis, int left, int need, int deep) {
	tempPath[deep] = u;
	if (d[u] < dis)
		return;
	//printf(" --- u = %d ---\n", u);
	if (u == T) {
		if (minBring > need) {
			minBring = need;
			minLef = left;
			cntP = deep + 1;
			Fin(i, 0, deep)
				path[i] = tempPath[i];
		}
		else if(minBring == need && minLef > left) {
			minLef = left;
			cntP = deep + 1;
			Fin(i, 0, deep)
				path[i] = tempPath[i];
		}
		return;
	}
	for (int i = vex[u].first; ~i; i = edge[i].next) {
		int & v = edge[i].t;
		if (visit[v] || d[u] + edge[i].len > d[v])
			continue;		
		visit[v] = true;
		if (vex[v].c > CMAX / 2)
			Dfs(v, dis + edge[i].len, left + vex[v].c - CMAX / 2, need, deep + 1);
		else {
			if (left >= CMAX / 2 - vex[v].c)
				Dfs(v, dis + edge[i].len, left - (CMAX / 2 - vex[v].c), need, deep + 1);
			else
				Dfs(v, dis + edge[i].len, 0, need + (CMAX / 2 - vex[v].c - left), deep + 1);
		}
		visit[v] = false;
	}
}
void Handle() {
	Dij();
	memset(visit, false, sizeof visit);
	minLef = minBring = INF;
	visit[S] = true;
	Dfs(S, 0, 0, 0, 0);
	printf("%d 0", minBring);
	Fin(i, 1, cntP - 1)
		printf("->%d", path[i]);
	printf(" %d\n", minLef);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	S = 0;
	while (~SfI2(CMAX, N)) {
		SfI2(T, M);
		Init();
		Handle();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
