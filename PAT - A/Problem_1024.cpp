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
#define BASE 10
struct BigInt {
	int arr[MAXN], len;
	void Scan(char *p) {
		memset(arr, 0, sizeof arr);
		len = strlen(p);
		Fin(i, 0, len - 1)
			arr[i] = p[len - i - 1] - '0';
	}
	void AddRev() {
		int res = 0;
		Fin(i, 0, len / 2 - 1)
			arr[i] = arr[len - i - 1] = arr[i] + arr[len - i - 1];
		if (len % 2)
			arr[len / 2] += arr[len / 2];
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
	bool Judge() {
		Fin(i, 0, len / 2 - 1)
			if (arr[i] != arr[len - i - 1])
				return false;
		return true;
	}
	void Print() {
		Fde(i, len - 1, 0)
			putchar(arr[i] + '0');
		putchar('\n');
	}
}x;
char str[MAXN];
int K;
int Print(){
	int cnt = 0;
	do {
		if (x.Judge() || cnt == K)
			return cnt;
		++cnt;
		x.AddRev();
	} while (1);
	return -1;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	int res;
	while (~SfS(str)) {
		x.Scan(str);
		SfI(K);
		res = Print();
		x.Print();
		printf("%d\n", res);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
