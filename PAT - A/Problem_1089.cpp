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
void Print(int p[], int n) {
	Fin(i, 1, N)
		printf("%d%c", p[i], i != N ? ' ' : '\n');
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
int temp[MAXN];
void Merge(int p[], int L1, int R1, int L2, int R2) {
	int p1 = L1, p2 = L2, pt = L1;
	while (p1 <= R1 && p2 <= R2) {
		temp[pt++] = p[p1] <= p[p2] ? p[p1++] : p[p2++];
	}
	while (p1 <= R1)
		temp[pt++] = p[p1++];
	while (p2 <= R2)
		temp[pt++] = p[p2++];
	Fin(i, L1, R2)
		p[i] = temp[i];
}
void MergeSort(int p[], int n) {
	bool flag = false;
	for (int size = 1; size < n; size *= 2) { // 块大小
		for (int st = 1; st <= n; st += 2 * size) {
			if (st + size - 1>= n) continue; // 一块以内，不用归并
			Merge(p, st, st + size - 1, st + size, min(st + size * 2 - 1, n));
		}
		if (!flag && Equal(res, p, N)) {
			printf("Merge Sort\n");
			flag = true;
		}
		else if (flag && !Equal(res, p, N)) {
			Fin(i, 1, N)
				printf("%d%c", p[i], i != N ? ' ' : '\n');
			return;
		}
	}
}
void Init() {
	Fin(i, 1, N)
		SfI(arrA[i]), arrB[i] = arrA[i];
	Fin(i, 1, N)
		SfI(res[i]);
	if (InsertSort(arrA, N))
		return;
	else
		MergeSort(arrB, N);
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
