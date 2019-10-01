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

#define MAX_COIN 10050
#define MAX_NEED 120
#define NIL -1

int dp[MAX_NEED], coins[MAX_COIN];
bool choice[MAX_COIN][MAX_NEED];
int N, M;
void Init() {
	Fin(i, 1, N)
		SfI(coins[i]);
	sort(coins + 1, coins + 1 + N);
}
int path[MAX_COIN];
void Cal() {
	memset(choice, false, sizeof choice);
	memset(dp, 0, sizeof dp);
	Fde(k, N, 1) {
		Fde(i, M, coins[k]) {
			if (dp[i] <= dp[i - coins[k]] + coins[k]) {
				dp[i] = dp[i - coins[k]] + coins[k];
				choice[k][i] = true;
			}
			else
				choice[k][i] = false;
		}
	}
	if (dp[M] != M) {
		printf("No Solution\n");
		return;
	}
	int val = M, cnt = 0;
	Fin(i, 1, N) {
		if (choice[i][val])
			path[++cnt] = i, val -= coins[i];
	}
	Fin(i, 1, cnt)
		printf("%d%c", coins[path[i]], i == cnt ? '\n' : ' ');
}

int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, M)) {
		Init();
		Cal();
	}
#ifdef DEBUG
while (1);
#endif // DEBUG
	return 0;
}


//
