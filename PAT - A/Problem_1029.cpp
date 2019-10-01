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

#define Fin(i,f,t) for(i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfD(x) scanf("%lf",&x)
#define SfLL(x) scanf("%lld",&x)
#define SfL(x) scanf("%ld",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 2 * 100000
#define NIL -1
int arr[MAXN], b;
int n1, n2;
int Median() {
	int mid = (n1 + n2 - 1) / 2 + 1, p = 0, res = NIL;
	int i, j;
	Fin(i, 1, n2) {
		SfL(b);
		while (p < n1 && p + i < mid && arr[p] < b)
			++p; // p end in p == n1 or p + i == mid or arr[p] >= b
		if (p == n1) {	// error for arr1 has drain out without the res out
			Fin(j, p + i + 1, mid)
				++i, SfL(b);
			res = b;
			break;
		}
		if (p + i == mid) {
			res = min(arr[p], b);
			break;
		}
	}
	if (!(~res) && i == n2 + 1) // error for arr2 has drain out without the res out
		res = arr[mid - n2 - 1];
	// handle the garbage
	Fin(i, i + 1, n2)
		SfL(b);
	return res;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	int i;
	while (~SfI(n1)) {
		Fin(i, 0, n1 - 1)
			SfL(arr[i]);
		SfI(n2);
		printf("%ld\n", Median());
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
