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
#define MAX_LEN 20
#define NIL -1
struct Obj {
	char str[MAX_LEN];
	int id, len;
	void Scan(int i) {
		SfS(str);
		len = strlen(str);
		id = i;
	}
	bool operator <(const Obj& A) {
		int maxLen = max(len, A.len);
		for (int i = 0; i < maxLen; ++i)
			if (str[i%len] != A.str[i%A.len])
				return str[i%len] < A.str[i%A.len];
		if (len != A.len)
			return len > A.len;
		return id < A.id;
	}
}objs[MAXN];
int N;
void Scan() {
	Fin(i, 0, N - 1)
		objs[i].Scan(i);
	sort(objs, objs + N);
}
bool preZero;
void Print() {
	preZero = true;
	Fin(i, 0, N - 1) {
		Obj & obj = objs[i];
		Fin(j, 0, obj.len-1) if (!preZero || obj.str[j] != '0') {
			preZero = false;
			putchar(obj.str[j]);
		}
	}
	if (preZero)
		putchar('0');
	putchar('\n');
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Scan();
		Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 一道有趣的贪心题目
// 反例：
//
//	input :  2 123 12312 
//  right :  12312123
//  output : 12312312
// 处理方式1：比较长度为最小公倍数
// 处理方式2：同前循环前缀，则长者优先
