#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <climits>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfD(x) scanf("%lf",&x)
#define SfLL(x) scanf("%lld",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAX_NUM 20500
#define LEN_DIS 10000

#define MAXN 350
#define NIL -1
int Hash(char p[]) {
	int start = 0, hash;
	if (p[start] == '-')
		++start;
	sscanf(p + start, "%d", &hash);
	hash += start * LEN_DIS;
	return hash;
}
int AntiHash(int x) {
	return x < 10000 ? x : x - 10000;
}
int table[MAX_NUM], antiTable[MAXN], cntV = 0, gender[MAXN];
int GetID(char p[]) {
	int loc = Hash(p);
	if (table[loc]) // 节点存在
		return table[loc];
	table[loc] = ++cntV;
	gender[cntV] = loc >= 10000;
	antiTable[cntV] = AntiHash(loc);
	//printf("%d is %d\n", cntV, antiTable[cntV]);
	return cntV;
}
bool mat[MAXN][MAXN];
int N, K, Q;
char str[10];
void Init() {
	cntV = 0;
	memset(mat, false, sizeof mat);
	memset(table, 0, sizeof table);
	int f, t;
	Fin(i, 1, K) {
		SfS(str); f = GetID(str);
		SfS(str); t = GetID(str);
		mat[f][t] = mat[t][f] = true;
	}
}
struct Fri {
	int id, name;
	bool operator <(const Fri & A)const {
		return name < A.name;
	}
}fA[MAXN], fB[MAXN];
int cntA, cntB;
void Query() {
	int a, b;
	SfS(str); a = GetID(str);
	SfS(str); b = GetID(str);
	cntA = cntB = 0;
	Fin(i, 1, cntV) if (mat[a][i] && i != a && i != b && gender[i] == gender[a]) {
		fA[cntA].name = antiTable[i];
		fA[cntA++].id = i;
	}
	Fin(i, 1, cntV) if (mat[b][i] && i != a && i != b && gender[i] == gender[b]) {
		fB[cntB].name = antiTable[i];
		fB[cntB++].id = i;
	}
	sort(fA, fA + cntA);
	sort(fB, fB + cntB);
	int res = 0;
	Fin(i, 0, cntA - 1)
		Fin(j, 0, cntB - 1) if (fA[i].id != fB[j].id &&mat[fA[i].id][fB[j].id])
			++res;
	printf("%d\n", res);
	Fin(i, 0, cntA - 1)
		Fin(j, 0, cntB - 1) if (fA[i].id != fB[j].id &&mat[fA[i].id][fB[j].id])
			printf("%04d %04d\n", fA[i].name, fB[j].name);
		
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, K)) {
		Init();
		SfI(Q);
		Fin(i, 1, Q)
			Query();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
