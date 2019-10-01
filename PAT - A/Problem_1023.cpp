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

#define MAXN 30
#define NIL -1
#define BASE 10

struct BigInt {
	int arr[MAXN], len;
	void Scan(char *p) {
		memset(arr, 0, sizeof arr);
		len = strlen(p);
		Fin(i, 0, len - 1)
			arr[i] = p[len - i - 1] - '0';
	}
	void Mult(int v) {
		Fin(i, 0, len - 1)
			arr[i] *= v;
		int carry = 0;
		Fin(i, 0, len - 1) {
			arr[i] += carry;
			carry = arr[i] / BASE;
			arr[i] %= BASE;
		}
		while (carry) {
			arr[len++] = carry % BASE;
			carry /= BASE;
		}
	}
	void Print() {
		Fde(i, len - 1, 0)
			putchar(arr[i] + '0');
		putchar('\n');
	}
}x;
char str[MAXN];
int times[10];
void Handle() {
	memset(times, 0, sizeof times);
	Fin(i, 0, x.len - 1)
		++times[x.arr[i]];
}
bool Judge() {
	Fin(i, 0, x.len - 1) {
		--times[x.arr[i]];
		if (times[x.arr[i]] < 0)
			return false;
	}
	return true;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	const int mult = 2;
	while (~SfS(str)) {
		x.Scan(str);
		Handle();
		x.Mult(mult);
		puts(Judge() ? "Yes" : "No");
		x.Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
