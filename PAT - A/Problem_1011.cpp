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
#define SfLL(x) scanf("%lld",x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG
#define MAXN 5
#define NIL -1
double odds[MAXN];
double MaxOdds() {
	int id = 1;
	Fin(i, 2, 3) if (odds[i] > odds[id])
		id = i;
	char letter = id <= 2 ? (id == 1 ? 'W' : 'T') : 'L';
	putchar(letter);
	putchar(' ');
	return odds[id];
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	double p = 0.65;
	Fin(i, 1, 3) {
		Fin(j, 1, 3)
			SfD(odds[j]);
		p *= MaxOdds();
	}
	printf("%0.2lf\n", (p - 1.0)*2.0);
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}
