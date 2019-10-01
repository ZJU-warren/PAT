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

#define MAXN 150
#define INF 0x3f3f3f3f
#define NIL	-1
struct Rec {
	char name[MAXN], id[MAXN];
	int grade;
	bool operator < (const Rec &A) const {
		return grade < A.grade;
	}
}rec[MAXN];
int N;
int LowerBound(int key) {
	int lef = 0, rig = N, mid;
	while (lef < rig) {
		mid = (lef + rig) / 2;
		if (rec[mid].grade < key)
			lef = mid + 1;
		else
			rig = mid;
	}
	return lef;
}
void Init() {
	Fin(i, 0, N - 1)
		scanf("%s %s %d", rec[i].name, rec[i].id, &rec[i].grade);
	sort(rec, rec + N);
	rec[N].grade = INF;
}
int L, R;
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		SfI2(L, R);
		if (R < L)
			swap(L, R);
		int s = LowerBound(R), cnt = 0;
		Fde(i, s, 0) {
			if (rec[i].grade > R)
				continue;
			if (rec[i].grade < L)
				break;;
			++cnt;
			printf("%s %s\n", rec[i].name, rec[i].id);
		}
		if (!cnt)
			puts("NONE");
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

//题解：
