#include <iostream>
#include <cstdio>
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

#define MAXN_N 55
#define MAXN_M 100050	
#define NIL	-1

int N, set[MAXN_N][MAXN_M];
bool visit[MAXN_N][MAXN_N];
double dp[MAXN_N][MAXN_N];
void Unique(int p[], int & len) {
	int j = 1;
	Fin(i, 2, len) if (p[i] != p[j])
		p[++j] = p[i];
	len = j;
}
void Init() {
	memset(visit, false, sizeof visit);
	Fin(i, 1, N) {
		SfI(set[i][0]);
		Fin(j, 1, set[i][0])
			SfI(set[i][j]);
		sort(set[i] + 1, set[i] + set[i][0] + 1);
		Unique(set[i], set[i][0]);
	}
}
double Cal(int a, int b) {
	if (visit[a][b])
		return dp[a][b];
	int i = 1, j = 1, same = 0, dif = 0;
	while (i <= set[a][0] && j <= set[b][0]) {
		if (i > 1 && set[a][i] == set[a][i - 1]) {
			++i;
			continue;
		}
		if (j > 1 && set[b][j] == set[b][j - 1]) {
			++j;	
			continue;
		}
		if (set[a][i] == set[b][j]) {
			++same, ++i, ++j;
		}
		else if (set[a][i] < set[b][j]) {
			++dif, ++i;
		}
		else {
			++dif, ++j;
		}
	}
	dif += (set[a][0] - (i - 1)) + (set[b][0] - (j - 1));
	visit[a][b] = visit[b][a] = true;
	return dp[a][b] = dp[b][a] = 100.0 * (double)same / (dif + same);
}
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		int K,a,b;
		SfI(K);
		Fin(k, 1, K) {
			SfI2(a, b);
			printf("%.1lf%%\n", Cal(a, b));
		}
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：WOA, 序列O(n)算法
