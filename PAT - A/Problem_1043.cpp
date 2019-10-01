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
struct Node {
	int lson, rson, v;
	void Init(int tv) {
		lson = rson = NIL;
		v = tv;
	}
}node[MAXN];
int preOrder[MAXN], inOrder[MAXN], N;
int cntNode, pos;
bool canBuild;
void Create(int L, int R,int & per, bool flag) { // org
	if (L > R)
		return;
	int mid;
	if(flag)
		for (mid = L; mid <= R && inOrder[mid] != preOrder[pos]; ++mid);
	else
		for (mid = R; mid >= L && inOrder[mid] != preOrder[pos]; --mid);
	if (mid < L || mid > R) {
		canBuild = false;
		return;
	}
	per = ++cntNode;
	node[per].Init(preOrder[pos++]);
	Create(L, mid - 1, node[per].lson, flag);
	Create(mid + 1, R, node[per].rson, flag);
}
void Init() {
	Fin(i, 0, N - 1)
		SfI(preOrder[i]), inOrder[i] = preOrder[i];
}
bool Cmp(const int a, const int b) {
	return a > b;
}
bool Judge() {
	pos = 0, canBuild = true;
	sort(inOrder, inOrder + N);
	Create(0, N - 1, node[0].lson, true);
	if (canBuild) 
		return true;
	pos = 0, canBuild = true;
	sort(inOrder, inOrder + N, Cmp);
	Create(0, N - 1, node[0].lson, false);
	return canBuild;
}
bool isHead;
void postOrder(int u) {
	if (u == NIL)
		return;
	postOrder(node[u].lson);
	postOrder(node[u].rson);
	if (isHead)
		isHead = false, printf("%d", node[u].v);
	else
		printf(" %d", node[u].v);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		if (Judge()) {
			printf("YES\n");
			isHead = true;
			postOrder(node[0].lson);
			putchar('\n');
		}
		else
			printf("NO\n");
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


// 16.25 - 17.01
