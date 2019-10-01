#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <cstdlib>
using namespace std;

#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfI3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 1200

int N, M, K;
int MyQueue[MAXN];
stack<int> S;
bool Judge() {
	while (!S.empty())
		S.pop();
	int p = N, q = N;
	S.push(MyQueue[q--]);
	while (p >= 1) {
		if (!S.empty() && p == S.top()) {
			S.pop();
			--p;
			continue;
		}
		if (q == 0 || !S.empty() && MyQueue[q] < S.top())
			return false;
		S.push(MyQueue[q--]);
		if ((int)S.size() > M)
			return false;
	}
	return true;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI3(M, N, K)) {
		Fin(k, 1, K) {
			Fin(i, 1, N)
				SfI(MyQueue[i]);
			printf("%s\n", Judge() ? "YES" : "NO");
		}
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG

	return 0;
}

// 题解： 
