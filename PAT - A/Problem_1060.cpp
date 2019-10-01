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
#define MAXN 1000

int VAILD_DIGITS;
struct Obj {
	char num[MAXN];
	int dot, len;
	bool flagVaild, flagDot;
	void Scan() {
		dot = len = 0;
		flagDot = flagVaild = false;
		while (num[len] = getchar()) {
			if (num[len] == ' ' || num[len] == '\n')
				break;
			if (!len && num[len] == '0') {// pre zero
				if (flagDot)
					--dot;
				continue;
			}
			if (num[len] == '.') {
				flagDot = true;
				if (flagVaild)
					dot = len;
			}
			else {
				flagVaild = true;
				++len;
			}
		}// end : len == 0 is v == 0
		if (!flagDot)
			dot = len;
		if (!flagVaild)
			dot = 0;
		Fin(i, len, VAILD_DIGITS - 1)
			num[i] = '0';
	}
	void Print() {
		printf("0.");
		Fin(i, 0, VAILD_DIGITS - 1)
			putchar(num[i]);
		printf("*10^%d", dot);
	}
	bool operator==(const Obj & A) const{
		if (dot != A.dot)
			return false;
		Fin(i, 0, VAILD_DIGITS - 1) if (num[i] != A.num[i])
			return false;
		return true;
	}
}a, b;
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(VAILD_DIGITS)) {
		getchar();
		a.Scan();
		b.Scan();
		if (a == b) {
			printf("YES ");
			a.Print();
			putchar('\n');
		}
		else {
			printf("NO ");
			a.Print();
			putchar(' ');
			b.Print();
			putchar('\n');
		}
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
