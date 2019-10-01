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

#define MAX_VEX 550
#define MAX_EDG (MAX_VEX * MAX_VEX)
#define NIL -1
#define INF 0x3f3f3f3f

struct V {
	int first;
	int attr[2]; // arr - 0 : dis, 1 : time
	int par[2];  // par - 0 : byDis, 1 : byTime
	void Init() {
		first = NIL;
		attr[0] = attr[1] = INF;
		par[0] = par[1] = NIL;
	}
}vex[MAX_VEX];
struct E {
	int next;
	int t, attr[3]; // arr - 0 : dis, 1 : time, 2 : chg
}edge[MAX_EDG];
int cntE;
void AddEdge(int f, int t, int d, int ti) {
	edge[cntE].t = t;
	edge[cntE].attr[0] = d;
	edge[cntE].attr[1] = ti;
	edge[cntE].attr[2] = 1;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}
int N, M;
void Init() {
	cntE = 0;
	Fin(i, 0, N - 1)
		vex[i].Init();
	int f, t, ow, len, time;
	Fin(i, 1, M) {
		SfI3(f, t, ow);
		SfI2(len, time);
		AddEdge(f, t, len, time);
		if(!ow)
			AddEdge(t, f, len, time);
	}
}
int disTemp[MAX_VEX], timTemp[MAX_VEX], chgTemp[MAX_VEX];
bool visit[MAX_VEX];
int S, T;
struct Elem {
	int id, first, second;
	Elem(int i,int f,int s):id(i),first(f),second(s){}
	Elem(){}
	bool operator<(const Elem & A) const {
		if (first != A.first)
			return first > A.first;
		return second > A.second;
	}
};
priority_queue<Elem> Q;
void Dij(int a[], int b[],int k1, int k2) {
	while (!Q.empty())
		Q.pop();
	memset(visit, false, sizeof visit);
	a[S] = b[S] = 0;
	Q.push(Elem(S, a[S], b[S]));
	int u, v;
	while (!Q.empty()) {
		u = Q.top().id;
		Q.pop();
		if (visit[u])
			continue;
		visit[u] = true;
		if (u == T)
			break;
		for (int i = vex[u].first; ~i; i = edge[i].next) {
			v = edge[i].t;
			if (visit[v]) continue;
			if (a[v] > a[u] + edge[i].attr[k1]) {
				a[v] = a[u] + edge[i].attr[k1];
				b[v] = b[u] + edge[i].attr[k2];
				vex[v].par[k1] = u;
			}
			else if (a[v] == a[u] + edge[i].attr[k1] && b[v] > b[u] + edge[i].attr[k2]) { // error : 运算符写错，别逗B了啊！
				b[v] = b[u] + edge[i].attr[k2];
				vex[v].par[k1] = u;
			}
			Q.push(Elem(v, a[v], b[v]));
		}
	}
	Fin(i, 0, N - 1)
		vex[i].attr[k1] = a[i];
}
void Cal() {
	memset(disTemp, 0x3f, sizeof disTemp);
	memset(timTemp, 0x3f, sizeof timTemp);
	memset(chgTemp, 0x3f, sizeof chgTemp);
	Dij(disTemp, timTemp, 0, 1);
	memset(disTemp, 0x3f, sizeof disTemp);
	memset(timTemp, 0x3f, sizeof timTemp);
	memset(chgTemp, 0x3f, sizeof chgTemp);
	Dij(timTemp, chgTemp, 1, 2);
}
bool Judge(int u) {
	int p1, p2;
	do {
		p1 = vex[u].par[0];
		p2 = vex[u].par[1];
		if (p1 != p2)
			return false;
		u = p1;
	} while (~u);
	return true;
}
void Print(int u, int i) {
	if (u == S)
		printf("%d", u);
	else {
		Print(vex[u].par[i], i);
		printf(" -> %d", u);
	}
}
void ShowUp() {
	if (Judge(T)) {
		printf("Distance = %d; Time = %d: ", vex[T].attr[0], vex[T].attr[1]);
		Print(T, 0); putchar('\n');
	}
	else {
		printf("Distance = %d: ", vex[T].attr[0]);
		Print(T, 0); putchar('\n');
		printf("Time = %d: ", vex[T].attr[1]);
		Print(T, 1); putchar('\n');
	}
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, M)) {
		Init();
		SfI2(S, T);
		Cal();
#ifdef DEBUG
		Fin(i, 0, N - 1)
			printf("vex[%d], dis:%d, dp = %d, tim:%d, tp = %d\n"
				, i, vex[i].attr[0], vex[i].par[0], vex[i].attr[1], vex[i].par[1]);
#endif // DEBUG
		ShowUp();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
