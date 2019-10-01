#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <climits>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define Fde(i,f,t) for(int i=f; i>=t; --i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfC(x) scanf("%c",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
#define SfLL(x) scanf("%lld",&x)
typedef long long LL;

//#define DEBUG
#define NIL -1
#define MAXN_N     100000
#define MAXN_PRIME 10000

struct Prime {
	int key, n;
	void Div(LL & v) {
		n = 0;
		do {
			n++;
			v /= key;
		} while (v && !(v%key));
		Print();
	}
	void Print() {
		printf("%d", key);
		if (n > 1)
			printf("^%d", n);
	}
}prime[MAXN_PRIME];
bool num[MAXN_N+50];
int cntPrime;
void Seive() {
	Fin(i, 2, MAXN_N) if (!num[i]) {
		prime[cntPrime++].key = i;
		for (LL j = (LL)i * i; j <= MAXN_N; j += i)
			num[j] = true;
	}
	//printf("%d %d\n", cntPrime, prime[cntPrime-1].key);
}
LL x;
void Handle() {
	bool flag = false;
	int i = 0;
	while (x > 1 && i < cntPrime) {
		if (!(x%prime[i].key)) {
			if (!flag)
				flag = true;
			else
				putchar('*');
			prime[i].Div(x);
		}
		++i;
	}
	if (x>1)
		printf("%s%lld", flag ? "*" : "", x);
	putchar('\n');
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	Seive();
	while (~SfLL(x)) {
		if (x == 1) {
			printf("1=1\n");
			continue;
		}
		printf("%lld=",x);
		Handle();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
