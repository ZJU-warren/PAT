#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <climits>
#include <cstdlib>
using namespace std;

#define Fin(i,f,t)	for(int i = f; i <= t; ++i)
#define Fde(i,f,t)	for(int i = f; i >= t; --i)
#define SfI(x)	scanf("%d",&x)
#define SfI2(x,y)	scanf("%d%d",&x,&y)
#define SfI3(x,y,z)	scanf("%d%d%d",&x,&y,&z)
#define SfLL(x)	scanf("%lld",&x)
#define SfD(x)	scanf("%lf",&x)
#define SfC(x)	scanf("%c",&x)
#define SfS(x)	scanf("%s",x)
typedef long long LL;

//#define DEBUG
#define MAXN 102000
#define NIL -1

int coins[MAXN], N, M;
int Find(int key, int lef, int rig) {
	int mid;
	while (lef < rig) {
		mid = (lef + rig) / 2;
		if (key <= coins[mid])
			rig = mid;
		else
			lef = mid + 1;
	}
#ifdef DEBUG
	printf("need = %d, find suitable is %d\n", coins[lef], key);
#endif // DEBUG
	return lef;
}
bool Judge() {
	int j;
	Fin(i, 0, N - 2) {
		j = Find(M - coins[i], i + 1, N);
		if (coins[i] + coins[j] == M) {
			printf("%d %d\n", coins[i], coins[j]);
				return true;
		}
	}
	return false;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, M)) {
		Fin(i, 0, N - 1)
			SfI(coins[i]);
		sort(coins, coins + N);
		if (!Judge())
			printf("No Solution\n");
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG

	return 0;
}
