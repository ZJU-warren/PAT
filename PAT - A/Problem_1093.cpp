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
const LL MOD = 1000000007;
char a[] = "PAT";
char arr[MAXN];				// index from 1
LL dp[MAXN], tpDp[MAXN];
LL Cal() {
	int len = strlen(arr + 1);
	memset(dp, 0, sizeof dp);
	memset(tpDp, 0, sizeof tpDp);
	Fin(i, 1, len) 
		dp[i] = dp[i - 1] + (arr[i] == a[0] ? 1 : 0);
	Fin(k, 1, 2) {
		Fin(i, 1, len)		// 前提是没有同元素
			tpDp[i] = arr[i] == a[k]? dp[i - 1] : 0;	
		Fin(i, 1, len)
			dp[i] = (dp[i - 1] % MOD + tpDp[i] % MOD) % MOD;
	}
	return dp[len];
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfS(arr + 1)) {
		printf("%lld\n", Cal());
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


//
