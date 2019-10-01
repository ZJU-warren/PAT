#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <map>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

#define MAXN 1055
#define NIL	-1

LL GCD(LL a, LL b) {
	return a%b ? GCD(b, a%b) : b;
}

LL LCM(LL a, LL b) {
	return a / GCD(a, b) * b;
}
struct Obj { // a + b/c , b = 0 || ( b < c and (b,c) = 1 )
	LL a, b, c;
	bool sign;
	void Scan(LL x, LL y) {
		b = x, c = y;
		// sign
		sign = b < 0 ? true : false;
		sign = c < 0 ? !sign : sign;	// look note : test2
		b = b < 0? -b : b;
		c = c < 0? -c : c;				// look note : test2
		// gcd
		LL gcd = GCD(b, c);
		b /= gcd;
		c /= gcd;
		// a + b / c
		a = b / c;
		b %= c;
	}
	void Print() {
		if (sign)	printf("(-");
		if (a)		printf("%lld%s", a,b?" ":"");
		if (b)		printf("%lld/%lld", b, c);
		if(!(a||b)) printf("0");		//error 1: all zero
		if (sign)	printf(")");
	}
}lef, rig, res;

LL a, b, c, d;
void Cal() {
	LL ra, rb;
	// +
	rb = LCM(b, d);
	ra = rb / b * a + rb / d * c;
	res.Scan(ra, rb);
	lef.Print(); cout << " + "; rig.Print(); cout << " = "; res.Print(); cout << endl;
	// -
	rb = LCM(b, d);
	ra = rb / b * a - rb / d * c;
	res.Scan(ra, rb);
	lef.Print(); cout << " - "; rig.Print(); cout << " = "; res.Print(); cout << endl;
	// *
	rb = b * d;
	ra = a * c;
	res.Scan(ra, rb);
	lef.Print(); cout << " * "; rig.Print(); cout << " = "; res.Print(); cout << endl;
	// /
	if (!c) {
		lef.Print(); cout << " / "; rig.Print(); cout << " = Inf" << endl;
	}
	else {
		rb = b * c;
		ra = a * d;
		res.Scan(ra, rb);
		lef.Print(); cout << " / "; rig.Print(); cout << " = "; res.Print(); cout << endl;
	}

}
int main()
{
	//freopen("e:\\test.txt","r",stdin);
	while (~scanf("%lld%*c%lld %lld%*c%lld",&a,&b,&c,&d)) {
		lef.Scan(a, b);
		rig.Scan(c, d);
		Cal();
	}
	return 0;
}
// 题解：没什么好说的，划水题
// test2 : 55144/71881 -58840/8844
