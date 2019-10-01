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

#define MAXN 20
#define NIL -1
struct Rec {
	string first, second;
	Rec(string a,string b):first(a),second(b){}
};
queue<Rec> Q;
char name[MAXN], pwd[MAXN];
int N, cnt;
char org[] = "10lO";
char tra[] = "@%Lo";
void Check() {
	bool flag = false;
	for (int i = 0; pwd[i]; ++i) {
		for (int j = 0; org[j]; ++j) if (pwd[i] == org[j]) {
			pwd[i] = tra[j];
			flag = true;
			break;
		}
	}
	if (flag) {
		++cnt;
		Q.push(Rec(name, pwd));
	}
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		while (!Q.empty())
			Q.pop();
		cnt = 0;
		Fin(i, 1, N) {
			SfS(name);
			SfS(pwd);
			Check();
		}
		if (!cnt)
			printf("There %s %d account%s and no account is modified\n", N == 1 ? "is" : "are", N, N == 1 ? "" : "s");
		else {
			printf("%d\n", cnt);
			while (!Q.empty()) {
				cout << Q.front().first << ' ' << Q.front().second << endl;
				Q.pop();
			}
		}
	}
#ifdef DEBUG
	//while (1);
#endif // DEBUG
	return 0;
}

// 题解： 一定要输出文本确认相同
