#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
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
#define SfI3(x,y,z) scanf("%d%d%d",&x,&y,&z)
typedef long long LL;

//#define DEBUG

#define MAX_USER 10050
#define MAX_PROB 7
#define NIL	-1
struct Stu {
	int id, solved, rank;
	int score[MAX_PROB], totScore;
	bool run[MAX_PROB];
	bool operator<(const Stu &A)const {
		if (totScore != A.totScore)
			return totScore > A.totScore;
		if (solved != A.solved)
			return solved > A.solved;
		return id < A.id;
	}
	void Init(int i) {
		id = i;
		totScore = solved = 0;
		Fin(i, 0, MAX_PROB - 1) 
			score[i] = NIL, run[i] = false;
	}
	void ShowUp(int K) {
		bool flag = false;
		Fin(i, 1, K)
			flag |= run[i];
		if (!flag)
			return;
		printf("%d %05d %d", rank, id, totScore);
		Fin(i, 1, K) {
			if (~score[i])
				printf(" %d", score[i]);
			else
				printf(" -");
		}
		putchar('\n');
	}
}stu[MAX_USER];

int s[MAX_PROB];
int N, K, M;
void Init() {
	Fin(i, 1, N)
		stu[i].Init(i);
	Fin(i, 1, K)
		SfI(s[i]);
	int id, pro, score;
	Fin(i, 1, M) {
		SfI3(id, pro, score);
		if (score == NIL)
			stu[id].score[pro] = max(stu[id].score[pro], 0);
		else {
			stu[id].score[pro] = max(stu[id].score[pro], score);
			stu[id].run[pro] = true;
		}
	}
}
void Handle() {
	Fin(i, 1, N) {
		Fin(k, 1, K) {
			stu[i].totScore += stu[i].run[k]? stu[i].score[k] : 0;
			stu[i].solved += (stu[i].score[k] == s[k]);
		}
	}
	sort(stu + 1, stu + N + 1);
	stu[1].rank = 1;
	Fin(i, 2, N)
		stu[i].rank = stu[i].totScore == stu[i - 1].totScore ? stu[i - 1].rank : i;
}
void Print() {
	Fin(i, 1, N)
		stu[i].ShowUp(K);
}
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~SfI3(N,K,M)) {
		Init();
		Handle();
		Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：	
