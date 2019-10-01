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
#define MAXN 60
#define NIL -1
int res[MAXN], order[MAXN], K;
void Shuffling(int i) {
	int finalLoc = i;
	Fin(k, 1, K)
		finalLoc = order[finalLoc];
	res[finalLoc] = i;
}
void Print(int x) {
	int a = x / 13;
	int b = x % 13;
	char letter;
	switch (a) {
	case 0: letter = 'S'; break;
	case 1: letter = 'H'; break;
	case 2: letter = 'C'; break;
	case 3: letter = 'D'; break;
	case 4: letter = 'J'; break;
	default: break;
	}
	printf("%c%d", letter, b+1);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(K)) {
		Fin(i, 1, 54)
			SfI(order[i]);
		Fin(i, 1, 54)
			Shuffling(i);
		Fin(i, 1, 54) {
			Print(res[i] - 1); // [1, 13], 所以左移一个
			putchar(i == 54 ? '\n' : ' ');
		}
	}
#ifdef DEBUG
	//while (1);
#endif // DEBUG
	return 0;
}

// 题解： 排序问题，常见
