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
#define MAXN 105000
#define NIL -1

LL d[MAXN];
int N, Q;
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		d[0] = 0;
		Fin(i, 1, N) {
			SfLL(d[i]);
			d[i] += d[i - 1];
		}
		SfI(Q);
		int f, t;
		Fin(q, 1, Q) {
			SfI2(f, t);
			if (f > t)
				swap(f, t);
			printf("%lld\n", min(d[t - 1] - d[f - 1], d[N] + d[f - 1] - d[t - 1]));
		}
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG

	return 0;
}
