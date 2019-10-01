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

#define MAX_PRIME 50000
#define NIL -1
bool num[MAX_PRIME + 20] = {};
int prime[MAX_PRIME + 20], cntPrime;
void Seive() {
	cntPrime = 0;
	Fin(i, 2, MAX_PRIME) if (!num[i]) {
		prime[cntPrime++] = i;
		for (LL j = (LL)i * i; j <= MAX_PRIME; j += i)
			num[j] = true;
	}
}
int LowerBound(int key) {
	int lef = 0, rig = cntPrime, mid;
	while (lef < rig) {
		mid = (lef + rig) / 2;
		if (prime[mid] < key)
			lef = mid + 1;
		else
			rig = mid;
	}
	return prime[lef];
}
int Q, N, TSIZE, arr[MAX_PRIME];
bool used[MAX_PRIME];
int resIdx;
bool Insert(int x) {
	LL base = x % TSIZE, add = 0;
	LL idx = base;
	do {
		if (!used[idx]) {
			arr[idx] = x, used[idx] = true, resIdx = idx;
			return true;
		}
		++add;
		idx = (base + (add % TSIZE) * (add % TSIZE)) % TSIZE;
	} while (add != TSIZE);
	return false;
}
void Init() {
	TSIZE = LowerBound(TSIZE);
	memset(used, false, sizeof used);
	int x;
	Fin(i, 1, N) {
		SfI(x);
		if (!Insert(x))
			putchar('-');
		else
			printf("%d", resIdx);
		printf("%c", i != N ? ' ' : '\n');

	}
}

int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	Seive();
	while (~SfI(TSIZE)) {
		SfI(N);
		Init();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


//
