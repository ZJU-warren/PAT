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
	char key;
	int next;
	bool visit;
	void Scan() {
		scanf("%*s");
		SfI(next);
		visit = false;
	}
}node[MAXN];

int head1, head2, N;
void Init() {
	int adr;
	Fin(i, 1, N) {
		SfI(adr);
		node[adr].Scan();
	}
}
int Trav(int st) {
	while (~st) {
		if (!node[st].visit)
			node[st].visit = true;
		else 
			return st;
		st = node[st].next;
	}
	return -1;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(head1, head2)) {
		SfI(N);
		Init();
		Trav(head1);
		int res = Trav(head2);
		if (~res) 
			printf("%05d\n", res);
		else 
			printf("-1\n");
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

