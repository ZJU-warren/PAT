#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG 

#define MAXN 10050
#define NIL -1

struct MyString {
	char str[10];
	void Scan() {
		SfS(str);
	}
	bool operator<(const MyString & A) const {
		return strcmp(str, A.str) < 0;
	}
};
struct Car{
	MyString name;
	int time;
	void Init(char *p) {
		strcpy(name.str, p);
		time = 0;
	}
}car[MAXN];

int cntCar;
struct Rec {
	int id, time;
	bool flag;
	bool operator<(const Rec & A) const {
		if (id != A.id)
			return id < A.id;
		if (time != A.time)
			return time < A.time;
		return flag < A.flag;
	}
	void Init(int tid, int ttime, bool tflag) {
		id = tid, time = ttime, flag = tflag;
	}
}record[MAXN];

map<MyString, int> M;
map<MyString, int> :: iterator it;
int getId(MyString &p) {
	if ((it = M.find(p)) != M.end())
		return it->second;
	car[++cntCar].Init(p.str);
	return M[p] = cntCar;
}
int GetTime() {
	int hh,mm,ss;
	scanf("%d%*c%d%*c%d", &hh,&mm,&ss);
	return (hh * 60 + mm) * 60 + ss;
}
char strTemp[10];
bool GetStatus() {
	SfS(strTemp);
	return strcmp(strTemp, "in")? true : false;
}

#define LIMIT (24 * 60 * 60)
#define lowbit(x) (x&-x)
int arr[LIMIT + 50];
void InitTree() {
	memset(arr, 0, sizeof arr);
}
void Update(int k, int add) {
	++k;
	for (; k <= LIMIT; arr[k] += add, k += lowbit(k));
}
int Sum(int k) {
	++k;
	int res = 0;
	for (; k > 0; res += arr[k], k -= lowbit(k));
	return res;
}
void ReNew(int L, int R, int add) {
	Update(L, add);
	Update(R + 1, -add);
}
bool MyCmp (const int a, const int b) {
	Car &A = car[a];
	Car &B = car[b];
	if (A.time != B.time)
		return A.time > B.time;
	return A.name < B.name;
}
int N, K;
MyString strName;
int res[MAXN];
void Init() {
	cntCar = 0;
	Fin(i, 0, N - 1) {
		SfS(strName.str);
		int id = getId(strName);
		int time = GetTime();
		bool status = GetStatus();
		record[i].Init(id, time, status); // 函数调用顺序问题！！！！
	}
	sort(record, record + N);
#ifdef DEBUG
	Fin(i, 0, N - 1)
		printf("%s %d %d\n", car[record[i].id].name.str, record[i].time, record[i].flag);
#endif // DEBUG

	Fin(i, 1, N - 1) {
		if (record[i].id != record[i - 1].id)
			continue;
		if (!record[i].flag || record[i - 1].flag)
			continue;
		ReNew(record[i-1].time, record[i].time-1, 1);
		car[record[i].id].time += record[i].time - record[i - 1].time;
	}
#ifdef DEBUG
	Fin(i, 1, cntCar)
		printf("%s  =  %d\n", car[i].name.str, car[i].time);
#endif // DEBUG
	Fin(i, 1, cntCar)
		res[i] = i;
	sort(res + 1, res + 1 + N, MyCmp);
}
void PrintTime(int time) {
	printf("%02d:%02d:%02d\n", time / 3600, (time % 3600) / 60, time % 60);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, K)) {
		Init();
		Fin(i, 1, K)
			printf("%d\n", Sum(GetTime()));
		Fin(i, 1, cntCar) {
			if (i != 1 && car[res[i]].time != car[res[i - 1]].time)
				break;
			printf("%s ", car[res[i]].name.str);
		}
		PrintTime(car[res[1]].time);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


