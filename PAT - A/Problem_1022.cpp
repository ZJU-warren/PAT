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
#define PtS(x) printf("%s\n",x)
typedef long long LL;

//#define DEBUG

#define MAXN 10500
#define MAX_STR 100
#define NIL -1
char NONE[MAX_STR];
struct Keyword {
	char str[15];
	Keyword(char p[]) {
		str[0] = p[0];
		for (int i = 1; p[i - 1]; ++i)
			str[i] = p[i];
	}
	Keyword(const Keyword & x) {
		str[0] = x.str[0];
		for(int i = 1; x.str[i - 1]; ++i)
			str[i] = x.str[i];
	}
	Keyword(char *p, int len) {
		Fin(i, 0, len - 1)
			str[i] = p[i];
		str[len] = 0;
	}
	bool operator<(const Keyword & A) const {
		return strcmp(str, A.str) < 0;
	}
};
struct V {
	int first, tail;
}vex[MAXN];
struct E {
	int t, next;
}edge[MAXN * 7];
int cntE, cntV;
void AddEdge(int f, int t) {
	edge[cntE].t = t;
	if (vex[f].first == NIL)
		vex[f].tail = vex[f].first = cntE;
	else
		edge[vex[f].tail].next = cntE;
	edge[cntE].next = NIL;
	vex[f].tail = cntE++;
	
}
void GraphInit() {
	cntV = cntE = 0;
	Fin(i, 0, MAXN - 1)
		vex[i].first = vex[i].tail = NIL;
}
map<Keyword, int> Encode;
int GetId(Keyword x) {
	int res = Encode[x];
	if (res)
		return res;
	Encode[x] = ++cntV;
	return cntV;
}
struct Books {
	char str[6][MAX_STR]; // 0 : title, 1 : name, 2 : keyword, 3 : publisher, 4 : year, 5 : id;
	void Scan() {
		cin.getline(str[5], MAX_STR);
		Fin(i, 0, 4)
			cin.getline(str[i], MAX_STR);
	}
	void HandleKeyword(int t) {
		int len = strlen(str[2]);
		str[2][len++] = ' ';
		str[2][len] = 0;
		int f;
		for (int i = 0, j = 0; i < len;) {
			while (str[2][j] != ' ') ++j;
			f = GetId(Keyword(str[2] + i, j - i));
			AddEdge(f, t);
			i = ++j;
			//printf("%d - %d\n", i, len);
		}
	}
#ifdef DEBUG
	void Print() {
		PtS(id);
		Fin(i, 0, 4)
			PtS(str[i]);
		PtS("________________");
	}
#endif // DEBUG
}books[MAXN];
int cmpIndex;
bool CmpByIndex(const int a, const int b) {
	int res = strcmp(books[a].str[cmpIndex], books[b].str[cmpIndex]);
	if (res) return res < 0;
	return    strcmp(books[a].str[5], books[b].str[5]) < 0;
}
int arr[6][MAXN], N;
void Init() {	
	Fin(i, 0, N - 1)
		books[i].Scan();		
	Fin(i, 0, 5) if(i != 2) { // remove the keywords
		Fin(k, 0, N - 1)
			arr[i][k] = k;
		cmpIndex = i;
		sort(arr[i], arr[i] + N, CmpByIndex);
	}
	// 给ID也排序，直接用到关键字表上连续性
	GraphInit();
	Fin(i, 0, N - 1)
		books[arr[5][i]].HandleKeyword(arr[5][i]);
	
}
int LowerBound(char key[], int p[], int i) {
	int lef = 0, rig = N, mid, cmp;
	while (lef < rig) {
		mid = (lef + rig) / 2;
		cmp = strcmp(books[p[mid]].str[i], key);
		if (cmp < 0)
			lef = mid + 1;
		else
			rig = mid;
	}
	return lef;
}
char query[MAX_STR];
void Query() {
	int index;
	scanf("%d%*c%*c",&index);
	cin.getline(query, MAX_STR);
#ifdef DEBUG
	printf("*******************  ");
#endif // DEBUG
	printf("%d: %s\n", index, query);
	--index;
	if(index != 2){ // 可有序查询的列
		int * res = &arr[index][0];
		int st = LowerBound(query, res, index);
	#ifdef DEBUG
		printf("-----------LIST BY %d ----%d-------\n", index, N);
		Fin(i, 0, N-1)
			books[res[i]].Print();
		printf("-----------  END -----------\n");
	#endif // DEBUG
		if (st == N || strcmp(books[res[st]].str[index], query)) {
			puts("Not Found");
			return;
		}
		while (st != N && !strcmp(books[res[st]].str[index], query))
			printf("%s\n", books[res[st]].str[5]), ++st;
	}
	else {
		int st = Encode[Keyword(query)];
		if(!st) {
			puts("Not Found");
			return;
		}
		for (int i = vex[st].first; ~i; i = edge[i].next)
			printf("%s\n", books[edge[i].t].str[5]);
	}
}

int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	int Q;
	while (~SfI(N)) {
		cin.getline(NONE, MAX_STR);
		Init();	
		SfI(Q);
		cin.getline(NONE, MAX_STR);
		Fin(q, 1, Q)
			Query();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}
