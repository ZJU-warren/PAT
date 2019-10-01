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
#define SfI3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SfD(x) scanf("%lf",&x)
#define SfLL(x) scanf("%lld",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 3500
#define NIL -1
#define INF 0x3f3f3f3f

int K, P, limit, arr[MAXN], N;
void Init() {
	limit = N;
	Fin(i, 1, N) {
		arr[i] = 1;
		Fin(p, 1, P)
			arr[i] *= i;
		if (arr[i] > N) {
			limit = i - 1;
			break;
		}
		//printf("%d^%d = %d\n",i, P, arr[i]);
	}
}
int res[MAXN], sumMin, tRes[MAXN];
bool flag;
void Dfs(int left, int deep, int idx, int sum) {
#ifdef DEBUG
	if (!left)
		printf("lef = %d, deep = %d, idx = %d, sum = %d\n",left,deep,idx,sum);
#endif // DEBUG
	if (left < deep)
		return;
	if (left < 0)
		return;
	if (deep == 0) {
		if (left != 0)
			return;
#ifdef DEBUG
		printf("%d = %d", N, arr[tRes[K]]);
		Fde(i, K - 1, 1) {
			printf(" + %d", arr[tRes[i]]);
		}
		putchar('\n');
		printf("__________________________\n");
#endif // DEBUG

		flag = true;
		if (sumMin < sum) {
			sumMin = sum;
			Fin(i, 1, K)
				res[i] = tRes[i];
		}
		return;
	}
	if (left == deep) {
		Fde(i, deep, 1)
			tRes[i] = 1;
		Dfs(0, 0, 0, sum + deep);
	}
	int i;
	for (i = idx; i >= 1 && left < arr[i] ; --i);
	if (!i) return;
	for (; i >= 1; --i) {
		tRes[deep] = i;
		Dfs(left - arr[i], deep - 1, i, sum + i);
	}
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		SfI2(K, P);
		Init();
		sumMin = -1;
		flag = false;
		Dfs(N, K, limit, 0);
		if (!flag)
			puts("Impossible");
		else {
			printf("%d = %d^%d", N, res[K], P);
			Fde(i, K - 1, 1) {
				printf(" + %d^%d", res[i], P);
			}
			putchar('\n');
		}
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
