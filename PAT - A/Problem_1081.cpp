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
#include <vector>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

//#define DEBUG

#define MAXN 120
#define NIL	-1

LL GCD(LL a, LL b) {
	return a % b ? GCD(b, a%b) : b;
}
LL LCM(LL a, LL b) {
	return a / GCD(a, b) * b;
}
LL a[MAXN], b[MAXN], mult, sum;
int N;
void Init() {
	mult = 1;
	sum = 0;
	Fin(i, 1, N) {
		scanf("%lld%*c%lld", &a[i], &b[i]);
		mult = LCM(mult, b[i]);
	}
	Fin(i, 1, N)
		sum += mult / b[i] * a[i];
	if (sum) {
		LL gcd = GCD(abs(sum), abs(mult));
		sum /= gcd;
		mult /= gcd;
	}
	//printf("%lld , %lld\n", sum, mult);
}
void Print() {
	LL intg = 0, fragN;
	intg = sum / mult;
	fragN = abs(sum % mult);
	if (intg) {
		printf("%lld", intg);
		if (fragN) printf(" %lld/%lld", fragN, mult);
		putchar('\n');
	}
	else {
		if (fragN) printf("%lld/%lld\n", fragN, mult);
		else printf("0\n");
	}
}
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

//题解：
