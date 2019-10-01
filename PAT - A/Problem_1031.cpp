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

#define MAXN 1050
#define NIL -1

int Cal(int n) {
	int i;
	for (i = 1; i <= (n + 2) - 2 * i; ++i);
	return i - 1;
}
char arr[MAXN];
void Print(int n1, int n2, int n) {
	Fin(i, 0, n1 - 2) {
		putchar(arr[i]);
		Fin(i, 1, n2 - 2)
			putchar(' ');
		putchar(arr[n - i - 1]);
		putchar('\n');
	}
	Fin(i, 0, n2 - 1)
		putchar(arr[n1 - 1 + i]);
	putchar('\n');
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	int n1, n2, n;
	while (~SfS(arr)) {
		n = strlen(arr);
		n1 = Cal(n);
		n2 = n + 2 - n1 * 2;
		Print(n1, n2, n);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
