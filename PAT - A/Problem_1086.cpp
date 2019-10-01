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

#define MAXN 60
#define NIL -1

struct Node {
	int lson, rson, v;
	void Init(int vt) {
		lson = rson = NIL;
		v = vt;
	}
}node[MAXN];

int N;
int preOrder[MAXN], cntPre, inOrder[MAXN], cntIn, pos, cntNode;
void Create(int L, int R,int & per) {
	if (L > R)
		return;
	//printf("[%d, %d]\n", L, R);
	int mid = L;
	for (; mid <= R && inOrder[mid] != preOrder[pos]; ++mid);
	per = ++cntNode;
	node[per].Init(preOrder[pos++]);
	Create(L, mid - 1, node[per].lson);
	Create(mid + 1, R, node[per].rson);
}

bool flagHead;
void Post(int u) {
	if (u == NIL)
		return;
	Post(node[u].lson);
	Post(node[u].rson);
	if (!flagHead)
		flagHead = true, printf("%d", node[u].v);
	else
		printf(" %d", node[u].v);
}

char oper[MAXN];
int x;
bool GetOper() {
	SfS(oper);
	if (!strcmp(oper, "Pop"))
		return false;
	SfI(x);
	return true;
}
void Init() {
	cntPre = cntIn = 0;
	stack<int> S;
	do {
		if (GetOper()) {
			S.push(x);
			preOrder[cntPre++] = x;
		}
		else {
			inOrder[cntIn++] = S.top();
			S.pop();
		}
	} while (cntPre < N || !S.empty());
	pos = cntNode = 0;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		Create(0, N - 1, node[0].lson);
		flagHead = false;
		Post(node[0].lson);
		putchar('\n');
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


// 15.05 - 15.35
