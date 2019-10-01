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

#define MAXN 105000
#define NIL	-1

bool visit[MAXN];
int arr[MAXN], cntLinks, cntRs;
void Circle(int x) {
	if (visit[x] || x == arr[x]) {
		visit[x] = true;
		return;
	}
	++cntLinks;
	while(!visit[x]){
		visit[x] = true;
		x = arr[x];
		++cntRs;
	}
}
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	int N;
	while (~SfI(N)) {
		Fin(i, 0, N - 1)
			SfI(arr[i]);
		memset(visit, false, sizeof visit);
		cntLinks = cntRs = 0;
		Fin(i, 0, N - 1)
			Circle(i);
		int dr = arr[0] ? -1 : 1;
		printf("%d\n", cntLinks - 1 + cntRs + dr);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
