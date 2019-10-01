#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
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

#define MAXN 12000

bool judge[1 << 8];
char s1[MAXN], s2[MAXN];
void Init() {
	memset(judge, false, sizeof judge);
	cin.getline(s2, MAXN);
	for (int i = 0; s2[i]; ++i)
		judge[(int)s2[i]] = true;
}
void Print() {
	for (int i = 0; s1[i]; ++i) if (!judge[s1[i]])
		putchar(s1[i]);
	putchar('\n');
}

int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (cin.getline(s1, MAXN)) {
		Init();
		Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}
