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

#define MAXN 160000
#define NIL -1
LL arr[MAXN];
int N;
bool cant[MAXN];
void Handle() {
	memset(cant, false, sizeof cant);
	Fin(i, 1, N)
		SfLL(arr[i]);
	LL Max = arr[1];
	Fin(i, 2, N) {
		if (arr[i] < Max)
			cant[i] = true;
		Max = max(Max, arr[i]);
	}
	LL Min = arr[N];
	Fde(i, N-1, 1) {
		if (arr[i] > Min)
			cant[i] = true;
		Min = min(Min, arr[i]);
	}
}
void Print() {
	int cnt = 0;
	Fin(i, 1, N) if (!cant[i])
		++cnt;
	printf("%d\n", cnt);
	if (!cnt)
		putchar('\n');
	Fin(i, 1, N) if (!cant[i])
		printf("%lld%c", arr[i],--cnt ? ' ' : '\n');
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Handle();
		Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


//
