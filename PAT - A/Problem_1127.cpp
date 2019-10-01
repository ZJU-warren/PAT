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
	int lson, rson, v, level;
}node[MAXN];
int p, N, inOrder[MAXN], postOrder[MAXN], cntV;
void Create(int L, int R, int &per) {
	if (L > R)
		return;
	--p;
	int i;
	for (i = R; i >= L && inOrder[i] != postOrder[p]; --i);
	per = ++cntV;
	node[cntV].lson = node[cntV].rson = NIL;
	node[cntV].v = inOrder[i];
	Create(i + 1, R, node[per].rson);
	Create(L, i - 1, node[per].lson);
}
int que[MAXN][MAXN], maxLevel;
void Bfs() {
	queue<int> Q;
	memset(que, 0, sizeof que);
	maxLevel = 0;
	node[node[0].lson].level = 1;
	Q.push(node[0].lson);
	int u;
	while (!Q.empty()) {
		u = Q.front(); Q.pop();
		maxLevel = max(maxLevel, node[u].level);
		int & cnt = que[node[u].level][0];
		que[node[u].level][++cnt] = node[u].v;
		if (~node[u].lson) {
			node[node[u].lson].level = node[u].level + 1;
			Q.push(node[u].lson);
		}
		if (~node[u].rson) {
			node[node[u].rson].level = node[u].level + 1;
			Q.push(node[u].rson);
		}
	}
}
void Print() {
	printf("%d", que[1][1]);
	Fin(i, 2, maxLevel) {
		if (i % 2) {
			Fde(j, que[i][0], 1)
				printf(" %d", que[i][j]);
		}
		else {
			Fin(j, 1, que[i][0])
				printf(" %d", que[i][j]);
		}
	}
	putchar('\n');
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Fin(i, 0, N - 1)
			SfI(inOrder[i]);
		Fin(i, 0, N - 1)
			SfI(postOrder[i]);
		p = N;
		Create(0, N - 1, node[0].lson);
		Bfs();
		Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
