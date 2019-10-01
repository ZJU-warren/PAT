#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
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
#define SSfI(str,x) sscanf(str,"%d",&x)
typedef long long LL;

//#define DEBUG

#define MAXN 1500
#define NIL	-1

char WEEKDAYS[7][5] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
int CalMinute(char *a,char *b) {
	int i = 0;
	while (*a && *b) {
		if (isalpha(*a) && *a == *b)
			return i;
		++a, ++b, ++i;
	}
	return i;
}
inline int GetDay(char x, int &day) {
	if (day == NIL && 'A' <= x && x <= 'G')
		return x - 'A';
	return -1;
}
inline int GetHour(char x, int &hour) {
	if (hour == NIL && '0' <= x && x <= '9')
		return x - '0';
	if (hour == NIL && 'A' <= x && x <= 'N')
		return x - 'A' + 10;
	return -1;
}
void CalDayAndHours(char *a, char *b, int &day, int &hour) {
	day = hour = NIL;
	int res;
	for (int i = 0; a[i]; ++i)if (a[i] == b[i]) {
		if (~(res = GetDay(a[i], day)))
			day = res;
		else if (~day && ~(res = GetHour(a[i], hour)))
			hour = res;
	}
}
char str1[MAXN], str2[MAXN];
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	int day, hour, minute;
	while (~SfS(str1)) {
		SfS(str2);
		CalDayAndHours(str1, str2, day, hour);
		SfS(str1);
		SfS(str2);
		minute = CalMinute(str1, str2);
		printf("%s %02d:%02d\n", WEEKDAYS[day], hour, minute);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
