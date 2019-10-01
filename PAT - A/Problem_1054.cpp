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
#define SfC(x) scanf("%c",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
#define SfLL(x) scanf("%lld",&x)
typedef long long LL;

//#define DEBUG
#define NIL -1
#define MAXN 10000

struct Obj {
	int first, second;
	bool operator <(const Obj & A) const {
		return second > A.second;
	}
}obj[800 * 600 + 50];

map<int, int> Map;
map<int, int> ::iterator it;
int M, N;
void Init() {
	int x;
	Map.clear();
	Fin(i, 1, M) {
		Fin(j, 1, N) {
			SfI(x);
			++Map[x];
		}
	}
}
void Cal() {
	int cnt = 0;
	for (it = Map.begin(); it != Map.end(); ++it, ++cnt) {
		obj[cnt].first = it->first;
		obj[cnt].second = it->second;
	}
	sort(obj, obj + cnt);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(M, N)) {
		Init();
		Cal();
		printf("%d\n", obj[0].first);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
