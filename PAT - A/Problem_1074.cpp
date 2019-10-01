#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG 

#define MAXN 100500
#define NIL -1

struct Node {
	int key, next;
	void Init() {
		SfI2(key, next);
	}
}node[MAXN];
const int ROOT = MAXN - 1;
int head, N, K;
void Init() {
	int adr;
	Fin(i, 1, N) {
		SfI(adr);
		node[adr].Init();
	}
	node[ROOT].next = head;
}
void Handle() {
	int i, j;
	int chg;
	for (i = ROOT; ~i;) {
		j = i;
		Fin(k, 1, K) {
			if (j == NIL) break;
			j = node[j].next;
		}
		if (j == NIL) return;
		Fin(k, 1, K-1) {
			chg = node[i].next;
			node[i].next = node[chg].next;
			node[chg].next = node[j].next;
			node[j].next = chg;
		}
		Fin(k, 1, K)
			i = node[i].next;
	}
}
void Print(int u) {
	if (u == NIL)
		return;
	if (node[u].next != NIL)
		printf("%05d %d %05d\n", u, node[u].key, node[u].next);
	else
		printf("%05d %d -1\n", u, node[u].key);
	Print(node[u].next);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(head)) {
		SfI2(N, K);
		Init();
		Handle();
		Print(node[ROOT].next);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


