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
#define Fde(i,f,t) for(int i=f; i>=t; --i)
#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

//#define DEBUG

#define MAXN 55000
#define NIL	-1

char str[MAXN];
inline int Min() {
	int res = 0;
	Fin(i, 0, 3)
		res = res * 10 + str[i] - '0';
	return res;
}
inline int Max() {
	int res = 0;
	Fde(i, 3, 0)
		res = res * 10 + str[i] - '0';
	return res;
}
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	int v, lef, rig;
	while (~SfI(v)) {
		sprintf(str, "%04d", v);
		do {
			sort(str, str + 4);
			lef = Max();
			rig = Min();
			v = lef - rig;
			printf("%04d - %04d = %04d\n", lef, rig, v);
			sprintf(str, "%04d", v);
		} while (v && v != 6174);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
