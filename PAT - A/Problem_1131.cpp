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
#define SfLL(x) scanf("%lld",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAX_VEX 12000
#define MAX_EDG (120 * 100)
#define NIL -1
#define INF 0x3f3f3f3f

struct V {
	int first;
}vex[MAX_VEX];
struct E {
	int t, next, id;
}edge[2 * MAX_EDG];
int cntE;
void AddEdge(int f, int t, int i) {
	edge[cntE].t = t;
	edge[cntE].id = i;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}
int N, M;
void Init() {
	cntE = 0;
	memset(vex, 0xff, sizeof vex);
	int f, t;
	Fin(k, 1, N) {
		SfI2(M, f);
		Fin(i, 2, M) {
			SfI(t);
			AddEdge(f, t, k);
			AddEdge(t, f, k);
			f = t;
		}
	}
}
struct Rec {
	int per, comeLine, dis, chg;
	void Init() {
		per = comeLine = NIL;
		dis = chg = INF;
	}
	void Set(int p, int cl, int d, int c) {
		per = p, comeLine = cl;
		dis = d, chg = c;
	}
}rec[MAX_VEX];
bool visit[MAX_VEX];
// 只记录节点号的好处，因为它不一定只从一条边来，但是访问到它的时候，一定是（来者都更新过它）的最优路
queue<int> Q;
int S, T;
void Bfs() {
	while (!Q.empty()) Q.pop();
	Fin(i, 0, MAX_VEX - 1)
		rec[i].Init();
	memset(visit, false, sizeof visit);
	rec[S].Set(NIL, NIL, 0, -1);	//每条线都不同于NIL，故必然会+1
	Q.push(S);
	int u, v;
	while (!Q.empty()) {
		u = Q.front(); Q.pop();
		if (visit[u])
			continue;
		visit[u] = true;
		if (u == T)
			break;
		for (int i = vex[u].first; ~i; i = edge[i].next) {
			v = edge[i].t;
			if (rec[v].dis > rec[u].dis + 1) {
				rec[v].dis = rec[u].dis + 1;
				rec[v].per = u;
				rec[v].comeLine = edge[i].id;
				rec[v].chg = (edge[i].id != rec[u].comeLine) + rec[u].chg;
			}
			else if (rec[v].dis == rec[u].dis + 1 && rec[v].chg > (edge[i].id != rec[u].comeLine) + rec[u].chg) {
				rec[v].per = u;
				rec[v].comeLine = edge[i].id;
				rec[v].chg = (edge[i].id != rec[u].comeLine) + rec[u].chg;
			}		
			Q.push(v);
		}
	}
}
struct P {
	int line, s;
}p[MAX_VEX];
int cntP;
void Trav(int u) {
	if (rec[u].per != NIL) {
		Trav(rec[u].per);
		if (p[cntP].line != rec[u].comeLine) {
			p[++cntP].line = rec[u].comeLine;
			p[cntP].s = rec[u].per;
		}
	}	
}
void Query() { // 这里转化问题为链表输出方法
	SfI2(S, T);
	Bfs();
	printf("%d\n", rec[T].dis);
	cntP = 0;
	p[0].line = NIL;
	Trav(T);
	p[cntP + 1].s = T;
	Fin(i, 1, cntP)
		printf("Take Line#%d from %04d to %04d.\n", p[i].line, p[i].s, p[i + 1].s);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		int Ques;
		SfI(Ques);
		Fin(i, 1, Ques)
			Query();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 出数据测试很重要. 注意变量重名问题
// note: (a == b) 这样的用真值赋值的时候一定要加括号，要不然不知道和哪个鬼运算符先匹配了
