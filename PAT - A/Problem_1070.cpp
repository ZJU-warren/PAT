#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

//#define DEBUG

#define MAXN 55000
#define NIL	-1

struct Obj {
	double num, price, unit;
	bool operator<(const Obj &A) const {
		return unit > A.unit;
	}
}objs[MAXN];

int N, D;
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~SfI2(N, D)) {
		Fin(i, 0, N - 1)
			SfD(objs[i].num);
		Fin(i, 0, N - 1) {
			SfD(objs[i].price);
			objs[i].unit = objs[i].price / objs[i].num;
		}
		sort(objs, objs + N);
		double res = 0;
		Fin(i, 0, N - 1) {
			if (D <= objs[i].num) {
				res += objs[i].unit * D;
				break;
			}
			D -= objs[i].num;
			res += objs[i].price;
		}
		printf("%.2lf\n", res);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
