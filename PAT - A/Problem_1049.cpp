#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)
#define Fin(i,f,t) for(int i = f; i <= t; ++i)
typedef long long LL;

#define MAX_LEN 11

LL dp[MAX_LEN + 5][10] = {};
LL power10[MAX_LEN + 5] = { 1 };

void Init() {
	Fin(i, 1, MAX_LEN)
		power10[i] = power10[i - 1] * 10;
	Fin(k, 1, MAX_LEN) {
		Fin(j, 0, 9)
			dp[k][0] += dp[k - 1][j];
		Fin(i, 1, 9)
			dp[k][i] = dp[k][0] + (i == 1? power10[k - 1] : 0);
	}
}
LL MyStoI(char p[]) {
	LL res;
	sscanf(p, "%lld", &res);
	return res;
}
char num[20];
int len;
LL res;
void Cal(int k) {
	if (k == len) {
		res += ((num[k] - '0')? 1 : 0);
		return;
	}
	Fin(j, 0, num[k] - '0' - 1)
		res += dp[len - k + 1][j];
	if (num[k] - '0' == 1)
		res += MyStoI(num + k + 1) + 1;
	Cal(k + 1);
}
int main(void) {
	Init();
	while (~SfS(num + 1)) {
		res = 0, len = strlen(num + 1);
		Cal(1);
		printf("%lld\n", res);
	}
	return 0;
}
