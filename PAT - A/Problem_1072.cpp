#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
#define SSfI(str,x) sscanf(str,"%d",&x)
typedef long long LL;

//#define DEBUG

#define MAXNV 1500
#define MAXNE 21500	
#define NIL	-1

int N, M, K;
double DS;

char temp[20];
int GetId() {
	SfS(temp);
	int id;
	if (temp[0] == 'G') {
		SSfI(temp + 1, id);
		return id + N;
	}
	SSfI(temp, id);
	return id;
}

struct V {
	int first;
	// belong to stations
	double minDis, avgDis;
	bool suitable;
}vex[MAXNV];
struct E {
	int t, next;
	double dis;
}edge[MAXNE];
int cntE;
void AddEdge(int f, int t, double dis) {
	edge[cntE].t = t;
	edge[cntE].dis = dis;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}

void Init() {
	cntE = 0;
	Fin(i, 1, N + M) {
		vex[i].first = NIL;
		vex[i].suitable = false;
	}
	int f, t;
	double dis;
	Fin(i, 1, K) {
		f = GetId();
		t = GetId();
		SfD(dis);
		AddEdge(f, t, dis);
		AddEdge(t, f, dis);
	}
}

double d[MAXNV];
bool visit[MAXNV];
struct Point {
	int u;
	double d;
	Point(int u, double d) :u(u), d(d) {}
	bool operator<(const Point &A) const {
		return d > A.d;
	}
};
priority_queue<Point> Q;
void Dij(int id) {
	while (!Q.empty()) Q.pop();
	Q.push(Point(id, d[id]));
	int u, v;
	while (!Q.empty()) {
		u = Q.top().u;
		Q.pop();
		if (visit[u])
			continue;
		visit[u] = true;
		for (int i = vex[u].first; ~i; i = edge[i].next) {
			v = edge[i].t;
			if (visit[v]) continue;
#ifdef DEBUG
			if (u <= N) printf("%d to ", u); else printf("G%d to ", u - N);
			if (v <= N) printf("%d ", v); else printf("G%d ", v - N);
			printf("is %.1lf, %.1lf, %.1lf\n", edge[i].dis, d[u], d[v]);
#endif // DEBUG
			if (d[v] > d[u] + edge[i].dis) {
				d[v] = d[u] + edge[i].dis;
				Q.push(Point(v, d[v]));
			}
		}
	}
}
void Handle(int id) {
	Fin(i, 1, N + M)
		d[i] = DS * 2; // INF
	memset(visit, false, sizeof visit);
	d[id] = 0;
	Dij(id);
#ifdef DEBUG
	printf("_________________RES_____________________\n");
	Fin(i, 1, N) printf("G%d to %d is %.1lf\n", id - N, i, d[i]);
	printf("________________END_RES_____________________\n");
#endif // DEBUG
	Fin(i, 1, N) if (d[i] > DS)
		return;
	vex[id].suitable = true;
	vex[id].avgDis = 0;
	vex[id].minDis = DS*2;
	Fin(i, 1, N) {
		vex[id].avgDis += d[i];
		vex[id].minDis = min(vex[id].minDis, d[i]);
	}
	vex[id].avgDis /= N;
	//printf("%d ,minDis is %lf, avgDis is %lf\n", id, vex[id].minDis, vex[id].avgDis);
}
int Cal() {
	int res = NIL;
	for (int i = N + 1; i <= N + M; ++i) if(vex[i].suitable){
		if (res == NIL)
			res = i;
		else {
			if (vex[i].minDis > vex[res].minDis)
				res = i;
			else if (vex[i].minDis == vex[res].minDis && vex[i].avgDis < vex[res].avgDis)
				res = i;
		}
	}
	return res;
}
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~scanf("%d %d %d %lf", &N, &M, &K, &DS)) {
		Init(); 
		Fin(i, 1, M)
			Handle(N + i);
		int res = Cal();
		if (~res)
			printf("G%d\n%.1lf %.1lf\n",res-N,vex[res].minDis, vex[res].avgDis);
		else
			puts("No Solution");
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


// 题解：
