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

#define MAXN 1050
#define NIL -1
char str[MAXN];
bool dp[MAXN][MAXN];
int len;
int Cal() {
	len = strlen(str + 1);
	memset(dp, false, sizeof dp);
	bool flag = false;
	Fin(i, 1, len) {
		dp[i][i] = true;
		if (str[i] == str[i + 1])
			flag = dp[i][i + 1] = true;
	}
	int res = flag ? 2 : 1;
	int j;
	Fin(dis, 3, len) {
		flag = false;
		Fin(i, 1, len) {
			j = i + dis - 1;
			if (j > len)
				break;
			dp[i][j] = dp[i + 1][j - 1] & (str[i] == str[j]);
			if (dp[i][j]) flag = true;			
		}
		if (flag)
			res = dis;
	}
	return res;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (cin.getline(str+1, MAXN)) {
		printf("%d\n", Cal());
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


//
