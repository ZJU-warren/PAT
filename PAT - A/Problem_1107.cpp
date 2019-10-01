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

#define MAXN 1050
#define NIL -1
#define INF 0x3f3f3f3f

int par[MAXN], num[MAXN];
void SetInit() {
	Fin(i, 1, 1000){ // error : Fin(i, 1, MAXN){ 导致溢出，把下面的N溢出为0了！
		par[i] = i;
		num[i] = 0;
	}
		
}
int Find(int x) {
	//printf("par[%d] = %d\n", x, par[x]);
	return par[x] = x == par[x] ? x : Find(par[x]);
}
void Unite(int x, int y) {
	x = Find(x);
	y = Find(y);
	par[y] = x;
}
int N;
void Init() {
	SetInit();
	int K, f, t;
	Fin(i, 1, N) {
		scanf("%d%*c%*c%d", &K, &f);
		++num[f];
		Fin(i, 2, K) {
			SfI(t);
			Unite(f, t);
		}
	}
}
bool Cmp(int a, int b) {
	return a > b;
}
void Cal() {
	int cnt = 0;
	Fin(i, 1, MAXN) {
		if (i != Find(i)) {
			num[Find(i)] += num[i];
			num[i] = 0;
		}
		else if (num[i] > 0)
			++cnt;
	}
	printf("%d\n", cnt);
	if (!cnt) {
		putchar('\n');
		return;
	}
	sort(num + 1, num + MAXN + 1, Cmp);
	Fin(i, 1, MAXN) {
		printf("%d%c", num[i], --cnt ? ' ' : '\n');
		if (!cnt) break;
	}
}
char str[MAXN];
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		Cal();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
