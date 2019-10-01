#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <map>
#include <queue>
#include <map>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

#define MAXN 225
#define NIL	-1

struct V {
	int first, hp;
	string str;
}vex[MAXN];
struct E {
	int  next, cost, t;
}edge[MAXN*MAXN];

int cntE;
void AddEdge(int f, int t, int c) {
	edge[cntE].t = t;
	edge[cntE].next = vex[f].first;
	edge[cntE].cost = c;
	vex[f].first = cntE++;
}

map<string, int> decode;
void InitMap() {
	cntE = 0;
	Fin(i, 0, MAXN - 1)
		vex[i].first = NIL;
	decode.clear();
}

struct Rec {
	int num, cost, hp;
	double avg;
	Rec(int num = 0, int cost = INT_MAX, int hp = 0) : num(num), cost(cost), hp(hp) {
		if(num)
			avg = (double) hp / num;
	}
	bool operator < (const Rec & A) const {
		if (cost != A.cost)
			return cost > A.cost;
		if (hp != A.hp)
			return hp < A.hp;
		return avg < A.avg;
	}
	bool operator == (const Rec & A) const {
		return cost == A.cost;
	}
};

int S, T, cntSame, path[MAXN], maxPath[MAXN];
Rec maxRes;
bool visit[MAXN];
void BackUp(int n) {
	Fin(i, 0, n)
		maxPath[i] = path[i];
}
void Dfs(int u, int num, int cost, int hp) {
	path[num] = u;
	if (u == T) {
		if (maxRes.cost < cost)
			return;
		cntSame = maxRes.cost == cost? cntSame + 1 : 1;
		//printf("{%d,%d,%d}\n", num, cost, hp);
		Rec now(num, cost, hp);
		if (maxRes < now) {
			maxRes = now;
			BackUp(num);
		}
		return;
	}
	int v;
	for (int i = vex[u].first; ~i; i = edge[i].next) {
		v = edge[i].t;
		if (visit[v])
			continue;
		visit[v] = true;
		Dfs(v, num + 1, cost + edge[i].cost, hp + vex[v].hp);
		visit[v] = false;
	}
}

void Print(int i) {
	int u = maxPath[i];
	if (u == T)
		cout << vex[u].str << endl;
	else {
		cout << vex[u].str << "->";
		Print(i + 1);
	}
}
void Cal() {
	memset(visit, false, sizeof visit);
	cntSame = 0;
	visit[S] = true;
	Dfs(S, 0, 0, 0);
	cout << cntSame << ' ' << maxRes.cost << ' ' << maxRes.hp << ' ' << (int)maxRes.avg << endl;
	Print(0);
}
int N, K;
string str;
void Scan() {
	InitMap();
	cin >> vex[1].str;
	S = 1;
	Fin(i, 2, N)
		cin >> vex[i].str >> vex[i].hp;
	Fin(i, 1, N) {
		decode[vex[i].str] = i;
		if (vex[i].str == "ROM")
			T = i;
	}
	string strF, strT;
	int c;
	Fin(i, 1, K) {
		cin >> strF >> strT >> c;
		AddEdge(decode[strF], decode[strT], c);
		AddEdge(decode[strT], decode[strF], c);
	}
}
int main()
{
	//freopen("e:\\test.txt","r",stdin);
	while (~SfI2(N, K)) {
		Scan();
		Cal();
	}
	//while (1);
	return 0;
}
// 题解：
