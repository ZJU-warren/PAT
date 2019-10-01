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

#define MAXN 105000
#define NIL -1
LL nevCou[MAXN], posCou[MAXN];
LL nevPro[MAXN], posPro[MAXN];
int nevCntCou, posCntCou, nC;
int nevCntPro, posCntPro, nP;
void Init() {
	nevCntCou = posCntCou = 0;
	nevCntPro = posCntPro = 0;
}
void Scan(LL a[], LL b[], int &cntA, int &cntB, int cnt) {
	LL x;
	Fin(i, 1, cnt) {
		SfLL(x);
		if (x > 0)
			a[cntA++] = x;
		else if (x < 0)
			b[cntB++] = -x;
	}
}
bool MyCmp(const int a, const int b) {
	return a > b;
}
LL res;
void Cal(LL a[], LL b[], int n) {
	Fin(i, 0, n - 1) {
		res += a[i] * b[i];
	}
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(nC)) {
		Scan(posCou, nevCou, posCntCou, nevCntCou, nC);
		SfI(nP);
		Scan(posPro, nevPro, posCntPro, nevCntPro, nP);
		sort(posCou, posCou + posCntCou, MyCmp);
		sort(nevCou, nevCou + nevCntCou, MyCmp);
		sort(posPro, posPro + posCntPro, MyCmp);
		sort(nevPro, nevPro + nevCntPro, MyCmp);
		res = 0;
		Cal(posCou, posPro, min(posCntCou, posCntPro));
		Cal(nevCou, nevPro, min(nevCntCou, nevCntPro));
		printf("%lld\n", res);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
