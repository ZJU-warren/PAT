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

#define MAXN 205500
#define NIL	-1

struct V {
	double price;
	int cntSon, first, num;
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
double price, r;
void Init(int N) {
	cntE = 0;
	Fin(i, 0, N - 1)
		vex[i].first = NIL;
	int t;
	Fin(i, 0, N - 1) {
		SfI(vex[i].cntSon);
		if (!vex[i].cntSon)
			SfI(vex[i].num);
		else {
			Fin(k, 1, vex[i].cntSon) {
				SfI(t);
				AddEdge(i, t);
			}
		}
	}
}
double tot;
void Dfs(int u) {
	if (!vex[u].cntSon) {
		tot += vex[u].num * vex[u].price;
		return;
	}
	int v;
	for (int i = vex[u].first; ~i; i = edge[i].next) {
		v = edge[i].t;
		vex[v].price = (r/100 + 1.0) * vex[u].price;
		Dfs(v);
	}
}
double Cal() {
	tot = 0;
	vex[0].price = price;
	Dfs(0);
	return tot;
}
int N;
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~scanf("%d %lf %lf", &N, &price, &r)) {
		Init(N);
		printf("%.1lf\n", Cal());
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
