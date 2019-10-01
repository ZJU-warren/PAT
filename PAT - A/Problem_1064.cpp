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
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG 

#define MAXN 1050
#define NIL -1
int N;
int tree[MAXN], cntTree, inOrder[MAXN];
void CreatePre(int i) {
	if (i > N)
		return;
	CreatePre(2 * i);
	tree[i] = inOrder[++cntTree];
	CreatePre(2 * i + 1);
}
void Init() {
	Fin(i, 1, N)
		SfI(inOrder[i]);
	sort(inOrder + 1, inOrder + N + 1);
	cntTree = 0;
	CreatePre(1);
}
void Level() {
	Fin(i, 1, N)
		printf("%d%c", tree[i], i != N ? ' ' : '\n');
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		Level();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


// 15.38 - 15.
