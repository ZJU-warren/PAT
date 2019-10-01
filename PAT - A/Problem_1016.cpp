#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <climits>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfD(x) scanf("%lf",&x)
#define SfLL(x) scanf("%lld",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 1050
#define NIL -1

struct MyString {
	char str[30];
	bool operator<(const MyString &A)const {
		return strcmp(str, A.str) < 0;
	}
	bool operator==(const MyString &A)const {
		return strcmp(str, A.str) == 0;
	}
	bool operator!=(const MyString &A)const {
		return strcmp(str, A.str) != 0;
	}
};
struct Time {
	int mouth, day, hour, minute;
	void Scan() {
		scanf("%d%*c%d%*c%d%*c%d", &mouth, &day, &hour, &minute);
	}
	void Print() {
		printf("%02d:%02d:%02d", day, hour, minute);
	}
	bool operator <(const Time & A)	const {
		if (mouth != A.mouth) return mouth < A.mouth;
		if (day != A.day) return day < A.day;
		if (hour != A.hour) return hour < A.hour;
		return minute < A.minute;
	}
	bool operator ==(const Time & A)	const {
		return day == A.day && hour == A.hour && minute == A.minute;
	}
	bool operator !=(const Time & A)	const {
		return !(*this == A);
	}
	void AddOne() {
		++minute;
		if (minute == 60)
			minute = 0, ++hour;
		if (hour == 24)
			hour = 0, ++day;
	}
};
char strTemp[100];
struct Rec {
	MyString name;
	Time t;
	bool isOnline; // true : online , false : offline
	void Scan() {
		SfS(name.str);
		t.Scan();
		SfS(strTemp);
		isOnline = !strcmp(strTemp, "on-line")? 1 : 0;
	}
#ifdef DEBUG
	void Print() {
		printf("%s ", name.str);
		t.Print();
		printf(" %d\n", isOnline);
	}
#endif // DEBUG
	bool operator <(const Rec & A)	const {
		int res = strcmp(name.str, A.name.str);
		if (res) return res < 0;
		return t < A.t;
	}
}rec[MAXN];

int costByTime[30], M;
void Init() {
	//cntHash = 0;
	Fin(i, 1, 23) {	// 前缀和形式，注意这只是分钟价格前缀和
		SfI(costByTime[i]);
		costByTime[i] += costByTime[i-1];
	}
	SfI(M);
	Fin(i, 0, M - 1)
		rec[i].Scan();
	sort(rec, rec + M);
#ifdef DEBUG
	Fin(i, 0, M - 1)
		rec[i].Print();
#endif // DEBUG
}

void CalCost(Time a, Time b,int & time,int & cost) {
	int res = 0;
	while (a != b) {
		cost += a.hour? costByTime[a.hour] - costByTime[a.hour-1] : costByTime[a.hour];
		++time;
		a.AddOne();
	}
}
void Handle() {
	bool start = true;
	int cost = 0, last = 0, spend = 0, num = 0;
	Fin(i, 1, M) {// 从1开始是因为记录0要么是上线，要么无效
		if (rec[i].name != rec[i - 1].name) {  // 刚开始不等，要么是上线，要么无效
			if (num)	// 处理之前的客户
				printf("Total amount: $%.2lf\n", (double)cost / 100);
			start = true;
			num = cost = 0;
			continue;
		}
		if (rec[i].isOnline)	//上线记录，要么有效，故留到下线处理，要么无效
			continue;
		if (!rec[i-1].isOnline)	//前记录也是下线，故无效
			continue;
		if (start) {
			printf("%s %02d\n", rec[i].name.str, rec[i].t.mouth);
			start = false;
		}
		++num;
		rec[i - 1].t.Print(); putchar(' ');
		rec[i].t.Print(); putchar(' ');
		last = spend = 0;
		CalCost(rec[i - 1].t, rec[i].t, last, spend);
		printf("%d $%.2lf\n", last, (double)spend/100);
		cost += spend;
	}
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(costByTime[0])) {
		Init();
		Handle();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}
// 题解： 模拟题，手速啊，OO啊
