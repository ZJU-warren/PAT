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
#define SfLL(x) scanf("%lld",x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG
#define MAXN 1050
#define NIL -1

struct V {
	int first;
}vex[MAXN];
struct E {
	int t, next;
}edge[MAXN*MAXN];
int cntE;
void AddEdge(int f, int t) {
	edge[cntE].t = t;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}
int N, M, K;
void Init() {
	cntE = 0;
	Fin(i, 1, N)
		vex[i].first = NIL;
	int f, t;
	Fin(i, 1, M) {
		SfI2(f, t);
		AddEdge(f, t);
		AddEdge(t, f);
	}
}
bool visit[MAXN];
void Dfs(int u) {
	visit[u] = true;
	for (int i = vex[u].first; ~i; i = edge[i].next)
		if (!visit[edge[i].t])
			Dfs(edge[i].t);
}
int Cal(int u) {
	int cnt = 0;
	memset(visit, false, sizeof visit);
	visit[u] = true;
	Fin(i, 1, N) if (!visit[i]) {
		++cnt;
		Dfs(i);
	}
	return cnt;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, M)) {
		SfI(K);		// error 3个数是一起给的，读取啊大哥，想啥那！
		Init();
		int u;
		Fin(i, 1, K) {
			SfI(u);
			printf("%d\n", Cal(u)-1);
		}
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 被自己蠢死，而且真的有的时候还是得测些小数据
