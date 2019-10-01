#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <climits>
#include <cstdlib>
using namespace std;

#define Fin(i,f,t)	for(int i = f; i <= t; ++i)
#define Fde(i,f,t)	for(int i = f; i >= t; --i)
#define SfI(x)	scanf("%d",&x)
#define SfI2(x,y)	scanf("%d%d",&x,&y)
#define SfI3(x,y,z)	scanf("%d%d%d",&x,&y,&z)
#define SfLL(x)	scanf("%lld",&x)
#define SfD(x)	scanf("%lf",&x)
#define SfC(x)	scanf("%c",&x)
#define SfS(x)	scanf("%s",x)
typedef long long LL;

//#define DEBUG
#define MAXN_S 40010
#define MAXN_V 2550

#define MAXN_E (MAXN_S*25)
#define NIL -1


struct V {
	int first;
}vex[MAXN_V];
struct E {
	int t, next;
}edge[MAXN_E];
int cntE;
void AddEdge(int f, int t) {
	edge[cntE].t = t;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}

char stu[MAXN_S][5];

int N, K;
void Init() {
	cntE = 0;
	Fin(i, 1, K) {
		vex[i].first = NIL;
	}
	int C, id;
	Fin(i, 1, N) {
		SfS(stu[i]);
		SfI(C);
		Fin(c, 1, C) {
			SfI(id);
			AddEdge(id, i);
		}
	}
}
int que[MAXN_S];
bool MyCmp(int a, int b) {
	return strcmp(stu[a], stu[b]) < 0;
}
void Print(int id) {
	int cnt = 0;
	for (int i = vex[id].first; ~i; i = edge[i].next)
		que[cnt++] = edge[i].t;
	printf("%d %d\n", id, cnt);
	sort(que, que + cnt, MyCmp);
	Fin(i, 0, cnt - 1)
		printf("%s\n", stu[que[i]]);
}

int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, K)) {
		Init();
		Fin(i, 1, K)
			Print(i);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}
