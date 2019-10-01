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

#define MAXN 3500
#define NIL -1

struct Node {
	int lson, rson, v, d;
}node[MAXN];
int cntV;
void Insert(int v, int & u) {
	if (u == NIL) {
		u = ++cntV;
		node[cntV].v = v;
		node[cntV].lson = node[cntV].rson = NIL;
		return;
	}
	if (v <= node[u].v)
		Insert(v, node[u].lson);
	else
		Insert(v, node[u].rson);
}
int MaxDeep(int u) {
	if (u == NIL)
		return 0;
	return max(MaxDeep(node[u].lson), MaxDeep(node[u].rson)) + 1;
}
int N;
void Init() {
	cntV = 0;
	int x;
	node[0].lson = NIL; // 记得初始化
	Fin(i, 1, N) {
		SfI(x);
		Insert(x, node[0].lson);
	}
#ifdef DEBUG
	Fin(i, 1, N) {
		printf("node%d : %d, %d, %d\n", i, node[i].v, node[i].lson, node[i].rson);
	}
#endif // DEBUG

}
void Cal() {
	int n1 = 0, n2 = 0, maxDeep = MaxDeep(node[0].lson), u;
	node[node[0].lson].d = 1;
	queue<int> Q;
	Q.push(node[0].lson);
	while (!Q.empty()) {
		u = Q.front(); Q.pop();
		n1 += (node[u].d == maxDeep);
		n2 += (node[u].d == maxDeep - 1);
		if (~node[u].lson) {
			node[node[u].lson].d = node[u].d + 1;
			Q.push(node[u].lson);
		}
		if (~node[u].rson) {
			node[node[u].rson].d = node[u].d + 1;
			Q.push(node[u].rson);
		}
	}
	printf("%d + %d = %d\n", n1, n2, n1 + n2);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		Cal();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
