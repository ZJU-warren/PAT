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

#define MAXN 1500
#define NIL -1

int M, N;
int arr[MAXN];
void Init() {
	Fin(i, 1, N)
		SfI(arr[i]);
}
bool head;
void PostOrder(int u) {
	if (u > N)
		return;
	PostOrder(2 * u);
	PostOrder(2 * u + 1);
	if (head)
		head = false, printf("%d", arr[u]);
	else
		printf(" %d", arr[u]);
}
bool flag;
void Dfs(int u, bool minHeap) {
	if (u > N)
		return;
	if (minHeap) {
		if (2 * u <= N && arr[2 * u] < arr[u]) flag = false;
		if (2 * u + 1 <= N && arr[2 * u + 1] < arr[u]) flag = false;
	}
	else {
		if (2 * u <= N && arr[2 * u] > arr[u]) flag = false;
		if (2 * u + 1 <= N && arr[2 * u + 1] > arr[u]) flag = false;
	}
	Dfs(2 * u, minHeap);
	Dfs(2 * u + 1, minHeap);
}
void Judge() {
	flag = true, Dfs(1, false);
	if (flag) {
		printf("Max Heap\n");
		return;
	}
	flag = true, Dfs(1, true);
	if (flag)
		printf("Min Heap\n");
	else
		printf("Not Heap\n");
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(M, N)) {
		Fin(m, 1, M) {
			Init();
			Judge();
			head = true;
			PostOrder(1);
			putchar('\n');
		}
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


//
