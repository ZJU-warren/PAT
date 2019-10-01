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

#define MAXN 2050
#define NIL -1

struct MyString {
	char p[4];
	void Scan() {
		SfS(p);
	}
	void Print() {
		printf("%s", p);
	}
	bool operator<(const MyString & A)	const {
		return strcmp(p, A.p) < 0;
	}
};

struct V {
	int first, id, tot;
}vex[MAXN];
struct E {
	int t, next, len;
}edge[MAXN * 2];
int cntE, cntV;
void AddEdge(int f, int t, int len) {
	edge[cntE].t = t;
	edge[cntE].len = len;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}

map<MyString, int> Encode;
map<int, MyString> Decode;
int GetID(MyString x) {
	int hash = Encode[x];
	if (hash)
		return hash;
	Encode[x] = ++cntV;
	Decode[cntV] = x;
	//printf("%s 's IDis %d\n", x.p, cntV);
	return cntV;
}

int N, K;
void Init() {
	cntV = cntE = 0;
	Fin(i, 0, MAXN - 1) {
		vex[i].first = NIL;
		vex[i].tot = 0;
	}
	MyString name;
	int f, t, len;
	Fin(i, 1, N) {
		name.Scan();
		f = GetID(name);
		name.Scan();
		t = GetID(name);
		SfI(len);
		AddEdge(f, t, len);
	}
}
bool visit[MAXN];
int link[MAXN], cntLink, v, totTime;
void Dfs(int u) {
	//printf("u = %d\n", u);
	for (int i = vex[u].first; ~i; i = edge[i].next) {
		v = edge[i].t;
		totTime += edge[i].len;
		vex[u].tot += edge[i].len;
		vex[v].tot += edge[i].len;
		if (!visit[v]) {
			visit[v] = true;
			link[cntLink++] = v;
			Dfs(v);
		}
	}
}
int getHead() {
	int head = link[0];
	Fin(i, 1, cntLink - 1) if (vex[head].tot < vex[link[i]].tot)
		head = link[i];
	return head;
}
int getHeadKey(int v) {
	MyString x = Decode[v];
	int key = 0;
	Fin(i, 0, 2)
		key = key * 26 + x.p[i] - 'A';
	return key;
}
struct Gang {
	int head, num, headKey;
	bool operator<(const Gang & A) const {
		return headKey < A.headKey;
	}
}gang[MAXN];
int cntGang;
void Handle() {
	cntGang = 0;
	Fin(i, 1, cntV) if (!visit[i]) {
		totTime = cntLink = 0;
		link[cntLink++] = i;
		visit[i] = true;
		Dfs(i);
		//printf("______________\n");
		if (cntLink > 2 && totTime > K) {
			gang[cntGang].num = cntLink;
			gang[cntGang].head = getHead();
			gang[cntGang].headKey = getHeadKey(gang[cntGang].head);
			++cntGang;
		}
	}
}
void Print() {
	printf("%d\n", cntGang);
	sort(gang, gang + cntGang);
	MyString x;
	Fin(i, 0, cntGang - 1) {
		x = Decode[gang[i].head];
		x.Print();
		printf(" %d\n", gang[i].num);
	}
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, K)) {
		Init();
		Handle();
		Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
