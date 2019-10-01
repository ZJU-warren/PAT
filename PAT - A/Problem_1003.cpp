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

#define MAXN 550
#define NIL	-1
#define INF 0x3f3f3f3f

struct V {
	int first, amount;
}vex[MAXN];
struct E {
	int t, len, next;
}edge[MAXN * MAXN];
int cntE;
void AddEdge(int f, int t, int l) {
	edge[cntE].t = t;
	edge[cntE].len = l;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}
int N, M, S, T;
void Init() {
	cntE = 0;
	Fin(i, 0, N - 1) {
		vex[i].first = NIL;
		SfI(vex[i].amount);
	}
	int f, t, l;
	Fin(i, 1, M) {
		SfI3(f, t, l);
		AddEdge(f, t, l);
		AddEdge(t, f, l);
	}
}
int minDis, maxAmount, cntRoad, d[MAXN];
//bool visit[MAXN];
struct Point {
	int u, d, mount;
	Point(int u, int d, int mount) : u(u), d(d), mount(mount){}
	bool operator <(const Point & A) const {
		return d > A.d;
	}
};
priority_queue<Point> Q;
void Dij() {
	while (!Q.empty()) Q.pop();
	//memset(visit, false, sizeof visit);
	memset(d, 0x3f, sizeof d);
	minDis = INF;
	maxAmount = -1;
	cntRoad = 0;
	d[S] = 0;
	Q.push(Point(S, d[S],vex[S].amount));
	int u, v, du, mount;
	while (!Q.empty()) {
		u = Q.top().u;
		mount = Q.top().mount;
		du = Q.top().d;
		Q.pop();
		if (d[u] > d[T])
			break;
		if (du > d[u])
			continue;
		//printf("u = %d, d[u] = %d\n", u, d[u]);
		if (u == T) {
			++cntRoad;
			maxAmount = max(mount, maxAmount);
			continue;
		}
		for (int i = vex[u].first; ~i; i = edge[i].next){
			v = edge[i].t;
			if (d[v] >= d[u] + edge[i].len) {
				d[v] = d[u] + edge[i].len;
				Q.push(Point(v, d[u] + edge[i].len, mount + vex[v].amount));
			}
		}
	}
}

int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~SfI2(N, M)) {
		SfI2(S, T);
		Init();
		Dij();
		printf("%d %d\n", cntRoad, maxAmount);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}
