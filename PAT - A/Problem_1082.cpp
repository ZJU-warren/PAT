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
#define Fde(i,f,t) for(int i=f; i>=t; --i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

//#define DEBUG

#define MAXN 15
#define NIL	-1
char numStr[10][10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
char powStr[9][10] = { "Fu", "Shi", "Bai", "Qian", "Wan", "Yi"};

int value[MAXN];
bool head;
void Print(char p[]) {
	int len = strlen(p);
	Fin(i, 0, len - 1)
		value[len - i - 1] = p[i] - '0';
	while (!value[len - 1]) --len;
	bool needZero = false;
	Fde(i, len - 1, 0) {
		if (value[i]) {
			if(needZero)
				printf("%s%s", head ? " " : "", numStr[0]), head = true;
			printf("%s%s", head ? " " : "", numStr[value[i]]), head = true;
			if (i % 4)
				printf(" %s", powStr[i % 4]);
			needZero = false;
		}
		else
			needZero = true;
		if (!(i % 4)) {
			if(i == 4)
				printf(" %s", powStr[4]);
			else if(i == 8)
				printf(" %s", powStr[5]);
			needZero = false;
		}
	}
	putchar('\n');
}
char arr[MAXN];
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~SfS(arr)) {
		bool notZero = false;
		head = false;
		for (int i = 0; arr[i]; ++i)
			if (arr[i] != '-' && arr[i] != '0')
				notZero = true;
		if (!notZero)
			printf("%s\n", numStr[0]);
		else if (arr[0] == '-') {
			printf("%s", powStr[0]);
			head = true;
			Print(arr + 1);
		}
		else
			Print(arr);
	}

#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

//题解：
