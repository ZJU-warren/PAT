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

#define MAXN 35
#define NIL -1
struct Node {
	int lson, rson, v;
	void Init(int tv) {
		v = tv;
		lson = rson = NIL;
	}
}node[MAXN];
int cntN;
int pre[MAXN], post[MAXN], N, preL;
bool vague;
void Create(int &par, int postL, int postR) {
	if (postL > postR)
		return;
	par = ++cntN;
	node[par].Init(pre[++preL]);
	--postR;
	int i = postR;
	if (postL > postR) return;
	for (; post[i] != pre[preL + 1] && i >= postL; --i);
	if (i == postR) {
		vague = true;
		Create(node[par].rson, postL, postR);
	}
	else {
		Create(node[par].lson, postL, i);
		Create(node[par].rson, i + 1, postR);
	}
}
bool first;
void InOrder(int u) {
	if (u == NIL)
		return;
	InOrder(node[u].lson);
	printf("%s%d", first ? "" : " ", node[u].v);
	first = false;
	InOrder(node[u].rson);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Fin(i, 1, N)
			SfI(pre[i]);
		Fin(i, 1, N)
			SfI(post[i]);
		preL = cntN = 0;
		vague = false;
		Create(node[0].lson, 1, N);
		puts(!vague ? "Yes" : "No");
		first = true;
		InOrder(node[0].lson); putchar('\n');
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： WOA, 看了一点题解思路
