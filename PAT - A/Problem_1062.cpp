#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
#define SSfI(str,x) sscanf(str,"%d",&x)
typedef long long LL;

//#define DEBUG

#define MAXN 105000
#define NIL	-1

struct Obj {
	int classify; // 0:sage, 1:nobleman, 2:fool man, 3:rest;
	int virtue, talent, total;
	char ID[10];
	void Scan() {
		SfS(ID);
		SfI2(virtue, talent);
		total = virtue + talent;
	}
	int Classify(int L, int H) {
		if (virtue < L || talent < L)
			return 0;
		if (virtue >= H && talent >= H)
			classify = 0;
		else if (virtue >= H)
			classify = 1;
		else if (virtue < H && virtue >= talent)
			classify = 2;
		else
			classify = 3;
		return 1;
	}
	bool operator <(const Obj & A) const {
		if (classify != A.classify)
			return classify < A.classify;
		if (total != A.total)
			return total > A.total;
		if (virtue != A.virtue)
			return virtue > A.virtue;
		return strcmp(ID,A.ID) < 0;
	}
	void Print() {
		cout << ID;
		printf(" %d %d\n", virtue, talent);
	}
}per[MAXN];
int N, M, L, H;
void Handle() {
	M = 0;
	Fin(i, 1, N) {
		per[M].Scan();
		M += per[M].Classify(L, H);
	}
}
void Print() {
	printf("%d\n", M);
	Fin(i, 0, M - 1)
		per[i].Print();
}
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~SfI(N)) {
		SfI2(L, H);
		Handle();
		sort(per, per + M);
		Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
