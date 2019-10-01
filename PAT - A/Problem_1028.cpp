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

#define MAXN 100500
#define NIL -1
int KeyID;
struct Obj {

	int id, grade;
	char name[10];
	bool operator<(const Obj & A) const {
		if (KeyID == 1)
			return id < A.id;
		else if (KeyID == 2) {
			int res = strcmp(name, A.name);
			return res? res < 0 : id < A.id;
		}
		else
			return grade != A.grade? grade < A.grade : id < A.id;
	}
}objs[MAXN];
int N;
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, KeyID)) {
		Fin(i, 0, N - 1)
			scanf("%d %s %d", &objs[i].id, objs[i].name, &objs[i].grade);
		sort(objs, objs + N);
		Fin(i, 0, N - 1)
			printf("%06d %s %d\n", objs[i].id, objs[i].name, objs[i].grade);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
