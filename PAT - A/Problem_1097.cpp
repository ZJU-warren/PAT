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

int head, N;
void Init() {
	int adr;
	Fin(i, 1, N) {
		SfI(adr);
		node[adr].Init();
	}
}

bool num[MAXN];
int delHead = NIL, delTail = NIL;
void Handle() {
	memset(num, false, sizeof num);
	int u, v;
	for (u = head; ~u;) {
		num[abs(node[u].key)] = true;
		int v = node[u].next;
		while (~v && num[abs(node[v].key)]) {
			node[u].next = node[v].next;
			if (delHead == NIL) {
				delHead = delTail = v;
				node[delTail].next = NIL;
			}
			else {
				node[v].next = node[delTail].next;
				node[delTail].next = v;
				delTail = v;
			}
			v = node[u].next;
		}
		u = node[u].next;
	}
}
void Trav(int u) {
	if (u == NIL)
		return;
	if(node[u].next != NIL)
		printf("%05d %d %05d\n", u, node[u].key, node[u].next);
	else
		printf("%05d %d -1\n", u, node[u].key);
	Trav(node[u].next);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(head, N)) {
		Init();
		Handle();
		Trav(head);
		Trav(delHead);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


