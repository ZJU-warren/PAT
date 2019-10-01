#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <climits>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define Fde(i,f,t) for(int i=f; i>=t; --i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfC(x) scanf("%c",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
#define SfLL(x) scanf("%lld",&x)
typedef long long LL;

//#define DEBUG
#define NIL -1
#define MAXN 10000

struct Obj {
	LL num[3];
	Obj() {
		Fin(i, 0, 2)
			num[i] = 0;
	}
	int Scan() {
		if (!(~SfLL(num[0])))
			return -1;
		getchar(); SfLL(num[1]);
		getchar(); SfLL(num[2]);
		return 3;
	}
	Obj operator + (const Obj & A) const {
		Obj res;
		res.num[2] = num[2] + A.num[2];
		res.num[1] = res.num[2] / 29;
		res.num[2] %= 29;

		res.num[1] += num[1] + A.num[1];
		res.num[0] = res.num[1] / 17;
		res.num[1] %= 17;

		res.num[0] += num[0] + A.num[0];
		return res;
	}
	void Print() {
		printf("%lld.%lld.%lld\n", num[0], num[1], num[2]);
	}
}a,b;
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~a.Scan()) {
		b.Scan();
		(a + b).Print();
	}
#ifdef DEBUG
	//while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
