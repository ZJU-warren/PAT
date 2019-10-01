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
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
#define SfI3(x,y,z) scanf("%d%d%d",&x,&y,&z)
typedef long long LL;

//#define DEBUG

#define MAXN 15
#define NIL	-1
#define INF	(LL)0X3f3f3f3f3f3f3f3f

inline int ValueOf(char x) {
	return '0' <= x && x <= '9' ? x - '0' : x - 'a' + 10;
}
struct Num {
	char num[MAXN];
	int LeastRadix() {
		int minRadix = -1;
		for (int i = 0; num[i]; ++i)		// 注意不合法的情况
			minRadix = max(ValueOf(num[i]), minRadix);
		return max(2, minRadix + 1);
	}
	LL Value(LL radix) {
		LL res = 0;
		for (int i = 0; num[i]; ++i) {
			res = res * radix + ValueOf(num[i]);
			if (res < 0)
				return NIL;
		}
		return res;
	}
}a[2];


LL res;
void Judge(int id) {// error : 因为两个数字不一定仅限于36进制内
	LL lef = a[id].LeastRadix(), rig = INF, mid;
	LL tempRes;
	while (lef < rig) {
		mid = (lef + rig) / 2;
		tempRes = a[id].Value(mid);
		if (~tempRes && tempRes < res)
			lef = mid + 1;
		else
			rig = mid;
	}
	if (a[id].Value(lef) == res)
		printf("%lld\n", lef);
	else
		printf("Impossible\n");
}
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	int radix, choice;
	while (~SfS(a[0].num)) {
		SfS(a[1].num);
		SfI2(choice, radix);
		--choice;
		res = a[choice].Value(radix);
		Judge((choice + 1) % 2);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
