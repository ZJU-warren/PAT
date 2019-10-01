#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG 

#define MAXN 100050
#define NIL -1

#define lowbit(x) (x & -x)

int arr[MAXN + 500];
int Sum(int k) {	// 求1`k的和
	int res = 0;
	for (; k > 0; res += arr[k], k -= lowbit(k));
	return res;
}
void Update(int k, int add) {	// 第k数加p
	for (; k <= MAXN; arr[k] += add, k += lowbit(k));
}
int Cal(int L, int R) {
	return Sum(R) - Sum(L - 1);
}
int LowerBound(int key){
	int L = 0, R = MAXN + 1, mid;
	while (L < R) {
		mid = (L + R) / 2;
		//printf("Sum(%d) = %d\n", mid, Sum(mid));
		if (Sum(mid) < key)
			L = mid + 1;
		else
			R = mid;
	}
	return L;
}
int N;
stack<int> S;
char oper[200];
int x;
void Oper() {
	SfS(oper);
	if (!strcmp(oper, "Push")) {
		SfI(x);
		S.push(x);
		Update(x, 1);
	}
	else {
		if (S.empty())
			printf("Invalid\n");
		else if (!strcmp(oper, "Pop")) {
			x = S.top();
			S.pop();
			Update(x, -1);
			printf("%d\n", x);
		}
		else
			printf("%d\n", LowerBound((S.size() - 1) / 2 + 1));
	}
}
void Init() {
	memset(arr, 0, sizeof arr);
	while (!S.empty())	
		S.pop();
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		Fin(i, 1, N)
			Oper();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}
