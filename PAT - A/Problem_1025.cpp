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

#define MAXN (105 * 300)
#define NIL -1
struct Stu {
	char id[20];
	int score, loc;
	int rank[2];	// rank[0] is loc, rank[1] is final
}stu[MAXN];
bool MyCmp(const Stu & A, const Stu & B) {
	if (A.score != B.score)
		return A.score > B.score;
	return strcmp(A.id, B.id) < 0;
}
int cnt, N;
void RankList(int L, int R,int keyId) {
	stu[L].rank[keyId] = 1;
	Fin(i, L + 1, R - 1)
		stu[i].rank[keyId] = stu[i].score == stu[i - 1].score ?
			stu[i - 1].rank[keyId] : i - L + 1;
}
void Init() {
	cnt = 0;
	int k;
	Fin(n, 1, N) {
		SfI(k);
		Fin(i, 0, k - 1) {
			scanf("%s %d", &stu[cnt + i].id, &stu[cnt + i].score);
			stu[cnt + i].loc = n;
		}
		sort(stu + cnt, stu + cnt + k, MyCmp);
		RankList(cnt, cnt + k, 0);
		cnt += k;
	}
}
void Cal() {
	sort(stu, stu + cnt, MyCmp);
	RankList(0, cnt, 1);
	printf("%d\n", cnt);
	Fin(i, 0, cnt - 1)
		printf("%s %d %d %d\n", stu[i].id, stu[i].rank[1], stu[i].loc, stu[i].rank[0]);
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		Init();
		Cal();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
