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

#define MAXN 100000
#define NIL -1

int arr[MAXN], num[MAXN], N;
int Handle() {
	memset(num, 0, sizeof num);
	Fin(i, 1, N)
		++num[arr[i]];
	Fin(i, 1, N) if (num[arr[i]] == 1)
		return arr[i];
	return -1;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Fin(i, 1, N)
			SfI(arr[i]);
		int res = Handle();
		if (~res)
			printf("%d\n", res);
		else
			printf("None\n");
	}
#ifdef DEBUG
	//while (1);
#endif // DEBUG
	return 0;
}

// 题解：
