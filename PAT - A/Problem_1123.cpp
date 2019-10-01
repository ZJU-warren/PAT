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

#define MAXN 160
#define NIL -1
struct Node {
	int lson, rson, v, height;
	void Init(int tv) {
		lson = rson = NIL;
		height = 1;
		v = tv;
	}
}node[MAXN];
int CalHeight(int u) {
	return ~u ? node[u].height : 0;
}
int CalBFactor(int u) {
	return CalHeight(node[u].lson) - CalHeight(node[u].rson);
}
void UpdateHeight(int u) {
	node[u].height = max(CalHeight(node[u].lson), CalHeight(node[u].rson)) + 1;
}
void MyR(int & root) {
	int temp = node[root].lson;
	node[root].lson = node[temp].rson;
	node[temp].rson = root;
	UpdateHeight(root);
	UpdateHeight(temp);
	root = temp;
}
void MyL(int & root) {
	int temp = node[root].rson;
	node[root].rson = node[temp].lson;
	node[temp].lson = root;
	UpdateHeight(root);
	UpdateHeight(temp);
	root = temp;
}
int cntNode;
void Insert(int & u, int key){
	if (u == NIL) {
		u = ++cntNode;
		node[u].Init(key);
		return;
	}
	if (key < node[u].v) {
		Insert(node[u].lson, key);
		UpdateHeight(u);
		if (CalBFactor(u) == 2) {
			if (CalBFactor(node[u].lson) == 1)
				MyR(u);
			else if (CalBFactor(node[u].lson) == -1) {
				MyL(node[u].lson);
				MyR(u);
			}
		}
	}
	else {
		Insert(node[u].rson, key);
		UpdateHeight(u);
		if (CalBFactor(u) == -2) {
			if (CalBFactor(node[u].rson) == -1)
				MyL(u);
			else if (CalBFactor(node[u].rson) == 1) {
				MyR(node[u].rson);
				MyL(u);
			}
		}
	}
}
int N;
void Init() {
	cntNode = 0;
	node[0].Init(0);
	int x;
	Fin(i, 1, N) {
		SfI(x);
		Insert(node[0].lson, x);
	}
}
bool Bfs() {
	bool flag = true;
	bool hvson = true;
	queue<int> Q;
	Q.push(node[0].lson);
	int x;
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		if (~node[x].lson) {
			if (!hvson)
				flag = false;
			Q.push(node[x].lson);
		}
		else
			hvson = false;
		if (~node[x].rson) {
			if (!hvson)
				flag = false;
			Q.push(node[x].rson);
		}
		else
			hvson = false;
		printf("%d%c", node[x].v, !Q.empty() ? ' ' : '\n');
	}
	return flag;
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		if (Bfs())
			printf("YES\n");
		else
			printf("NO\n");
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}
