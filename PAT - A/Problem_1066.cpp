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
	return u == NIL ? 0 : node[u].height;
}
int CalBalance(int u) {
	return CalHeight(node[u].lson) - CalHeight(node[u].rson);
}
void UpdateHeight(int u) {
	node[u].height = max(CalHeight(node[u].lson), CalHeight(node[u].rson)) + 1;
}
int cntNode;
void MyL(int & root) {	// 向左
	int temp = node[root].rson;
	node[root].rson = node[temp].lson;
	node[temp].lson = root;
	UpdateHeight(root);
	UpdateHeight(temp);
	root = temp;
}
void MyR(int & root) {	// 向右
	int temp = node[root].lson;
	node[root].lson = node[temp].rson;
	node[temp].rson = root;
	UpdateHeight(root);
	UpdateHeight(temp);
	root = temp;
}
void MyRL(int &u) {		// 先右后左
	MyR(node[u].rson);  // noticed!
	MyL(u);
}
void MyLR(int &u) {		// 先左后右
	MyL(node[u].lson);	// noticed!
	MyR(u);
}
void Insert(int &u, int key) {
	if (u == NIL) {
		u = ++cntNode;
		node[u].Init(key);
		return;
	}
	if (key < node[u].v) {
		Insert(node[u].lson, key);
		UpdateHeight(u);
		if (CalBalance(u) == 2) {
			if (CalBalance(node[u].lson) == 1) // LL
				MyR(u);
			else if (CalBalance(node[u].lson) == -1) // LR
				MyLR(u);
		}
	}
	else {
		Insert(node[u].rson, key);
		UpdateHeight(u);
		if (CalBalance(u) == -2) {
			if (CalBalance(node[u].rson) == -1) // RR
				MyL(u);
			else if (CalBalance(node[u].rson) == 1) // RL
				MyRL(u);
		}
	}
}
int N;
int & treeRoot = node[0].lson;
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		node[0].Init(0);
		cntNode = 0;
		int v;
		Fin(i, 1, N) {
			SfI(v);
			Insert(treeRoot, v);
		}
		printf("%d\n", node[treeRoot].v);
	}
	cntNode = 0;
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}
