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

#define MAXN 10050
#define NIL -1

int f[MAXN], arr[MAXN], N, M, L;
void Init() {
	memset(f, 0, sizeof f);
	SfI(M);
	int x;
	Fin(i, 1, M)
		SfI(x), f[x] = i;
	SfI(L);
	int cnt = 0;
	Fin(i, 1, L) {
		SfI(x);
		if (f[x])
			arr[++cnt] = f[x];
	}
	L = cnt;
}
LL dp[MAXN];
LL Cal() {
	memset(dp, 0, sizeof dp);
	LL maxv;
	Fin(i, 1, L) {
		maxv = dp[1];
		Fin(j, 2, arr[i])
			maxv = max(maxv, dp[j]);
		dp[arr[i]] = maxv + 1;
	}
	maxv = dp[1];
	Fin(i, 2, M)
		maxv = max(maxv, dp[i]);
	return maxv;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		printf("%lld\n", Cal());
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


//
