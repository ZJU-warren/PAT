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
#define SfI(x) scanf("%d",&x)
#define SfULL(x) scanf("%llu",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;
typedef unsigned long long ULL;

//#define DEBUG

#define MAXN 1050
#define NIL	-1

struct Obj {
	bool sign;
	ULL value;
	void Set(char *p) {
		if (p[0] == '-') {
			sign = 1;
			++p;
		}
		else
			sign = 0;
		sscanf(p, "%llu", &value);
	}
	void Print() {
		if (sign)
			putchar('-');
		cout << value << endl;
	}
	bool operator < (const Obj & A) const {
		if (sign ^ A.sign)
			return sign ? true : false;
		if (sign && A.sign)
			return value > A.value;
		return value < A.value;
	}
	bool operator ==(const Obj & A) const {
		return sign == A.sign && value == A.value;
	}
	bool operator >(const Obj & A) const {
		return  !(*this == A) && !(*this < A);
	}
	Obj operator +(const Obj & A) const {
		Obj c;
		if (sign ^ A.sign) {
			if (value == A.value) {
				c.sign = 0;
				c.value = 0;
			}
			else if (value < A.value) {
				c.sign = A.sign;
				c.value = A.value - value;
			}
			else {
				c.sign = sign;
				c.value = value - A.value;
			}
		}
		else {
			c.sign = sign;
			c.value = value + A.value;
		}
		return c;
	}
}a,b,c,Max,Min;

bool Judge() {
	return (a + b) > c;
}
char str[MAXN];
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	Max.sign = 0; Max.value = (ULL)1 << 63; Max.value -= 1; Max.value += (ULL)1 << 63;
	Min.sign = 1; Min.value = (ULL)1 << 63; Min.value -= 1; Min.value += (ULL)1 << 63;
	int T;
	SfI(T);
	Fin(t,1,T) {
		bool gt = true, lt = true;
		SfS(str); a.Set(str);
		if (strcmp("9223372036854775808", str)) gt = false;
		if (strcmp("-9223372036854775808", str)) lt = false;
		SfS(str); b.Set(str);
		if (strcmp("9223372036854775808", str)) gt = false;
		if (strcmp("-9223372036854775808", str)) lt = false;
		SfS(str); c.Set(str);

		if(gt)
			printf("Case #%d: %s\n", t, "true");
		else if(lt)
			printf("Case #%d: %s\n", t, "false");
		else
			printf("Case #%d: %s\n",t, (a + b) > c ? "true" : "false");
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
