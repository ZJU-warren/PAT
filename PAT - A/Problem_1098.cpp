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

#define MAXN 150
#define NIL 0
bool Equal(int a[], int b[], int n) {
	Fin(i, 1, n)
		if (a[i] != b[i])
			return false;
	return true;
}
int arrA[MAXN], arrB[MAXN], res[MAXN], N;
void Adjust(int p[], int i, int n) { // 最大堆
	if (i > n)
		return;
	int idx = i;
	if (2 * i <= n && p[2 * i] > p[idx]) idx = 2 * i;
	if (2 * i + 1 <= n && p[2 * i + 1] > p[idx]) idx = 2 * i + 1;
	if (idx != i)
		swap(p[i], p[idx]), Adjust(p, idx, n);
}
void Print(int p[], int n) {
	Fin(i, 1, N)
		printf("%d%c", p[i], i != N ? ' ' : '\n');
}
void BuildHeap(int p[], int n) {
	Fde(i, n / 2, 1) {
		Adjust(p, i, n);
	}
}
void HeapSort(int p[], int n) {
	bool flag = false;
	BuildHeap(p, n);
	Fde(i, n, 1) {
		swap(p[1], p[i]);
		Adjust(p, 1, i-1);
		if (!flag && Equal(res, p, N)) {
			printf("Heap Sort\n");
			flag = true;
		}
		else if(flag && !Equal(res, p, N)) {
			Print(p, N);
			return;
		}
	}
}
bool InsertSort(int p[], int n) {
	bool flag = false;
	int j;
	Fin(i, 2, n) {
		p[0] = p[i];
		for (j = i; j > 1 && p[j - 1] > p[0]; p[j] = p[j - 1], --j);
		p[j] = p[0];
		if (!flag && Equal(res, p, N)) {
			printf("Insertion Sort\n");
			flag = true;
		}
		else if (flag && !Equal(res, p, N)) {
			Fin(i, 1, N)
				printf("%d%c", p[i], i != N ? ' ' : '\n');
			return true;
		}
	}
	return flag;
}
void Init() {
	Fin(i, 1, N)
		SfI(arrA[i]), arrB[i] = arrA[i];
	Fin(i, 1, N)
		SfI(res[i]);
	if (InsertSort(arrA, N))
		return;
	else
		HeapSort(arrB, N);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}


//
