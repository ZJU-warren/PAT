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
typedef long long LL;

//#define DEBUG

#define MAXN 10050
#define NIL	-1
struct V {
	int first;
}vex[MAXN];
struct E {
	int t, next;
}edge[MAXN * 100];
int cntE;
void AddEdge(int f, int t) {
	edge[cntE].t = t;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}
int N, L, Ques;
void Init() {
	cntE = 0;
	Fin(i, 1, N)
		vex[i].first = NIL;
	int K, t;
	Fin(i, 1, N) {
		SfI(K);
		Fin(k, 1, K) {
			SfI(t);
			AddEdge(t, i);
		}
	}
}
int deg[MAXN];
bool visit[MAXN];
queue<int> Q;
int Bfs(int S) {
	memset(deg, 0, sizeof deg);
	memset(visit, false, sizeof visit);
	deg[S] = 0;
	visit[S] = true;
	int res = 0, v, u;
	while (!Q.empty())	Q.pop();
	Q.push(S);
	while (!Q.empty()) {
		u = Q.front(); Q.pop();
		if (deg[u] > L)
			break;
		++res;
		for (int i = vex[u].first; ~i; i = edge[i].next) {
			v = edge[i].t;
			if (visit[v]) continue;
			visit[v] = true;
			deg[v] = deg[u] + 1;
			Q.push(v);
		}
	}
	return res - 1;
}
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~SfI2(N, L)) {
		Init();
		SfI(Ques);
		int x; 
		Fin(i, 1, Ques) {
			SfI(x);
			printf("%d\n", Bfs(x));
		}
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：	
