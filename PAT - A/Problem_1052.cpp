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
#define SfI2(x, y) scanf("%d%d",&x,&y)
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG 

#define MAXN 100050
#define NIL -1

struct Node {
	int adr, key, next;
	bool used;
	void Init(int tadr) {
		adr = tadr;
		SfI2(key, next);
	}
	bool operator<(const Node & A) const {
		if (used != A.used)
			return used > A.used;
		return key < A.key;
	}
}node[MAXN];

int N, head;
void Init() {
	Fin(i, 0, MAXN - 1)
		node[i].used = false;
	int adr;
	Fin(i, 1, N)
		SfI(adr), node[adr].Init(adr);
	N = 0;
	for (int i = head; ~i; i = node[i].next)
		++N, node[i].used = true;
	sort(node, node + MAXN);
}
void Print() {
	if (N) {
		printf("%d %05d\n", N, node[0].adr);
		Fin(i, 0, N - 2)
			printf("%05d %d %05d\n", node[i].adr, node[i].key, node[i + 1].adr);
		printf("%05d %d -1\n", node[N - 1].adr, node[N - 1].key);
	}
	else
		printf("%d -1\n", N);		
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, head)) {
		Init();
		Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}
