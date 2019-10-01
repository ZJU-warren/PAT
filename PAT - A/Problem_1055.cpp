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
#define SfI3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SfC(x) scanf("%c",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
#define SfLL(x) scanf("%lld",&x)
typedef long long LL;

//#define DEBUG
#define NIL -1
#define MAXN 100200

struct Obj {
	char name[10];
	int age, worth;
	void Scan() {
		SfS(name);
		SfI2(age, worth);
	}
	bool operator<(const Obj & A) const {
		if (worth != A.worth)
			return worth > A.worth;
		if (age != A.age)
			return age < A.age;
		return strcmp(name, A.name) < 0;
	}
}obj[MAXN];

int N, K;
void Init() {
	Fin(i, 0, N - 1)
		obj[i].Scan();
	sort(obj, obj + N);
}
void Query(int n, int L, int H) {
	int cnt = 0;
	Fin(i, 0, N - 1) if (cnt < n && L <= obj[i].age && obj[i].age <= H) {
		printf("%s %d %d\n", obj[i].name, obj[i].age, obj[i].worth);
		++cnt;
	}
	if (!cnt)
		puts("None");
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, K)) {
		Init();
		int n, L, H;
		Fin(i, 1, K) {
			printf("Case #%d:\n", i);
			SfI3(n, L, H);
			Query(n, L, H);
		}
	}
#ifdef DEBUG
	//while (1);
#endif // DEBUG
	return 0;
}

// 题解：

