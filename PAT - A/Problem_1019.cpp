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
#define SfLL2(x,y) scanf("%lld%lld",&x,&y)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 1050
#define NIL -1
struct Num{
	LL arr[MAXN], v, b;
	int len;
	void Format() {
		len = 0;
		do{
			arr[len++] = v % b;
			v /= b;
		} while (v);
	}
	bool Judge() {
		Fin(i, 0, len / 2 - 1) if (arr[i] != arr[len - i - 1])
			return false;
		return true;
	}
	void Print() {
		Fde(i, len - 1, 0)
			printf("%lld%c", arr[i], i? ' ' : '\n');
	}
}x;
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfLL2(x.v, x.b)) {
		x.Format();
		puts(x.Judge() ? "Yes" : "No");
		x.Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
