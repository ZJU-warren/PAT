#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
using namespace std;

#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfI3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 120
#define NIL -1
struct V {
	int first;
	LL weight;
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
int N, M;
LL S;
void Init() {
	cntE = 0;
	Fin(i, 0, N - 1) {
		vex[i].first = NIL; ///// 前向星勿忘系列
		SfLL(vex[i].weight);
	}
	int f, t, K;
	Fin(i, 1, M) {
		SfI2(f, K);
		Fin(k, 1, K) {
			SfI(t);
			AddEdge(f, t);
		}
	}
}
struct Rec {
	int len;
	LL path[MAXN];
	bool operator < (const Rec & A) const {
		int minLen = min(len, A.len);
		Fin(i, 0, minLen - 1) if (path[i] != A.path[i])
			return path[i] > A.path[i];
		return false;
	}
	void Set(LL p[], int pLen) {
		len = pLen;
		Fin(i, 0, len - 1)
			path[i] = p[i];
	}
	void Print() {
		Fin(i, 0, len - 1)
			printf("%lld%c", path[i], i == len - 1 ? '\n' : ' ');
	}
}rec[MAXN];
int cntR;
LL p[MAXN];
void Dfs(int u, LL sum,int pLen) {
	if (sum == S && !(~vex[u].first)) {
		rec[cntR++].Set(p, pLen);
	}
	if (sum > S)
		return;
	for (int i = vex[u].first; ~i; i = edge[i].next) {
		p[pLen] = vex[edge[i].t].weight;
		Dfs(edge[i].t, sum + p[pLen], pLen + 1);
	}
}

int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, M)) {
		SfLL(S);
		Init();
		cntR = 0;
		p[0] = vex[0].weight;
		Dfs(0, vex[0].weight, 1);
		sort(rec, rec + cntR);
		Fin(i, 0, cntR - 1)
			rec[i].Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}
