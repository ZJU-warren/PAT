#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

#define MAXN 1055
#define NIL	-1

struct V {
	int level, first;
}vex[MAXN];
struct E {
	int next, t;
}edge[MAXN];
int cntE;
void AddEdge(int f, int t) {
	edge[cntE].t = t;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}
int lev[MAXN];
void Bfs() {
	queue<int> Q;
	vex[1].level = 1;
	Q.push(1);
	int u, v;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		++lev[vex[u].level];
		for (int i = vex[u].first; ~i; i = edge[i].next) {
			v = edge[i].t;
			vex[v].level = vex[u].level + 1;
			Q.push(v);
		}
	}
}
int N, M;
void Init() {
	memset(lev, 0, sizeof lev);
	cntE = 0;
	Fin(i, 1, N)
		vex[i].first = NIL;
	int u, v, k;
	Fin(i, 1, M) {
		SfI2(u, k);
		Fin(j, 1, k) {
			SfI(v);
			AddEdge(u, v);
		}
	}
}
void Cal() {
	int maxNum = 1, maxLev = 1,i = 2;
	while (lev[i]) {
		if (lev[i] > maxNum) {
			maxNum = lev[i];
			maxLev = i;
		}
		++i;
	}
	printf("%d %d\n", maxNum, maxLev);
}
int main()
{
	//freopen("e:\\test.txt","r",stdin);
	while (~SfI2(N, M)) {
		Init();
		Bfs();
		Cal();
	}
	return 0;
}
// 题解：
