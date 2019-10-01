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

#define MAXN 105000
#define NIL -1

struct Num {
	int v, b, len, arr[30];
	void Scan(int tv, int tb) {
		v = tv, b = tb;
		Format();
	}
	void Format() {
		len = 0;
		do {
			arr[len++] = v % b;
			v /= b;
		} while (v);
	}
	int Rev() {
		int res = 0;
		Fin(i, 0, len-1)
			res = res * b + arr[i];
		return res;
	}
}x;
bool isPrime[MAXN] = {1, 1};
void Seive() {
	Fin(i, 2, MAXN - 1) if (!isPrime[i])
		for (LL j = (LL)i * i; j <= MAXN - 1; j += i)
			isPrime[j] = true;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	int v, b;
	Seive();
	while (~SfI(v) && v >= 0) {
		SfI(b);
		x.Scan(v, b);
		printf("%s\n",!isPrime[v] && !isPrime[x.Rev()] ? "Yes" : "No");
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
