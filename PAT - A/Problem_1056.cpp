#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <climits>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define Fde(i,f,t) for(int i=f; i>=t; --i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfC(x) scanf("%c",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
#define SfLL(x) scanf("%lld",&x)
typedef long long LL;

//#define DEBUG
#define NIL -1
#define MAXN 10000

typedef int MyType;

struct Obj {
	int id, floor, rank;// , weight;
	MyType weight;
}obj[MAXN];

bool SortById(const Obj & A, const Obj & B) {
	return A.id < B.id;
}
bool SortByFloor(const Obj & A, const Obj & B) {
	return A.floor > B.floor;
}
int P, G;
int game[MAXN], cnt; // game[i] 是该轮第i个玩家的原始ID
void Init() {
	Fin(i, 0, P - 1) {
		obj[i].floor = 1;
		cin >> obj[i].weight;
		obj[i].id = i;
	}
	Fin(i, 0, P - 1)
		SfI(game[i]);
	cnt = P;
}

int Winner(int lef, int rig) {
	int maxI = lef;
	Fin(i, lef + 1, rig) 
		if (obj[game[maxI]].weight < obj[game[i]].weight)
			maxI = i;
	++obj[game[maxI]].floor;
	return game[maxI];
}
void Cal() {
	while (cnt > 1) {
		int tcnt = 0, last = 0;
		Fin(i, 1, cnt) if(i == cnt || !(i%G)){
			if (last <= i - 1){
				game[tcnt++] = Winner(last,i-1);
				last = i;
			}
		}
		cnt = tcnt;
	}
	sort(obj, obj + P, SortByFloor);
	obj[0].rank = 1;
	Fin(i, 1, P - 1)
		obj[i].rank = obj[i].floor == obj[i - 1].floor ? obj[i - 1].rank : i + 1;
	sort(obj, obj + P, SortById);
	Fin(i, 0, P - 1)
		printf("%d%c", obj[i].rank, i != P - 1 ? ' ' : '\n');
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(P, G)) {
		Init();		
		Cal();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
