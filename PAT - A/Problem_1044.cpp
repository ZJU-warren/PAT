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

#define MAXN 100050
#define NIL -1

LL arr[MAXN], M;
int N;
bool Handle() {
	int lef = 1, rig = 0;
	LL sum = 0, minSum = (LL)100000050;
	bool flag = false;
	for (; lef <= N;) {
		if (sum == M) {
			flag = true;
			printf("%d-%d\n", lef, rig);
		}
		if (sum >= M) {
			minSum = min(minSum,sum);
			sum -= arr[lef++];
		}
		else if (rig < N)
			sum += arr[++rig];
		else
			break;
	}
	M = minSum;
	return flag;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		SfLL(M);
		Fin(i, 1, N)
			SfLL(arr[i]);
		if(!Handle())
			Handle();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 尺取法，读题啊亲！
