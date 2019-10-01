#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <map>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
#define SfD2(x,y) scanf("%lf %lf",&x,&y)
typedef long long LL;

#define MAXN 105500
#define NIL	-1
#define EXP 1e-5

struct Obj {
	double price;
	int par;
	bool flag;
}node[MAXN];

int N;
double rootPrice, rate;

void Init() {
	Fin(i, 0, N - 1) {
		SfI(node[i].par);
		if (!(~node[i].par))
			node[i].price = rootPrice, node[i].flag = true;
		else
			node[i].flag = false;
	}
}

double Cal(int i) {
	if (node[i].flag)
		return node[i].price;
	node[i].flag = true;
	return node[i].price = Cal(node[i].par) * (rate/100.0 + 1);
}

int main()
{
	//freopen("e:\\test.txt","r",stdin);
	while (~SfI(N)) {
		SfD2(rootPrice, rate);
		Init();
		int cnt = 0;
		double maxPrice = -1, indexPrice;
		Fin(i, 0, N - 1) {
			indexPrice = Cal(i);
			if (indexPrice > maxPrice) {
				maxPrice = indexPrice;
				cnt = 1;
			}
			else if (fabs(maxPrice - indexPrice) < EXP)
				++cnt;
		}
		printf("%.2lf %d\n", maxPrice, cnt);
	}
	return 0;
}
// 题解：
