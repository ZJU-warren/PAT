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
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

//#define DEBUG

#define MAXN 55000
#define NIL	-1

struct Obj {
	char num[MAXN], sign;	// index from 1;
	int len, exp, dot;
	void Scan(char *p) {
		memset(num, 0, sizeof num);
		len = 0;
		num[0] = p[len++]; // sign
		num[1] = p[len++]; // int
		++p;		   // dot
		dot = 1;
;		do {
			num[len] = p[len];
		} while (p[++len] != 'E');
		num[len] = '\0';
		sscanf(p + len + 1, "%d", &exp);
	}
	void Print() {
		if (num[0] == '-')
			putchar('-');
		dot += exp;
		if (dot < 0) {
			printf("0.");
			Fin(i, 1, -dot)
				putchar('0');
			puts(num+1);
		}
		else {
			Fin(i, 1, dot)
				putchar(num[i]? num[i] : '0');
			if (num[dot + 1]) {
				putchar('.');
				puts(num + dot + 1);
			}
			else
				putchar('\n');
		}
	}

}obj;

char str[MAXN];
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~SfS(str)) {
		obj.Scan(str);
		obj.Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
