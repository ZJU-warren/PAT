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
#include <vector>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfD(x) scanf("%lf",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

//#define DEBUG

#define MAXN_APL 40550
#define MAXN_SCH 150
#define NIL	-1

struct School {
	int minRank, quoto, cnt;
	vector<int> admit;
	bool Admit(int i);
	void Display() {
		sort(admit.begin(), admit.end());
		Fin(i, 0, cnt - 1)
			printf("%d%s", admit[i], i != cnt - 1 ? " " : "");
		putchar('\n');
	}
}school[MAXN_SCH];

struct Apy {
	double GE, GI, GF;
	int choice[8], id, rank;
	bool operator < (const Apy & A) const {
		if (GF != A.GF)
			return GF > A.GF;
		return GE > A.GE;
	}
	void Scan(int i, int K) {
		id = i;
		SfD(GE);
		SfD(GI);
		GF = (GE + GI) / 2;
		Fin(i, 0, K - 1)
			SfI(choice[i]);
	}
	void Display(int K) {
		printf("___________Rank = %d, ID = %d___________\n", rank, id);
		printf("GF = %.2lf, GE = %.2lf, GI = %.2lf\n", GF, GE, GI);
		printf("choice : ");
		Fin(i, 0, K - 1)
			printf("%d ", choice[i]);
		putchar('\n');
	}
	void Handle(int K, int loc);
}apy[MAXN_APL];

bool School::Admit(int i) {
	if (cnt < quoto || minRank == apy[i].rank) {
		++cnt;
		minRank = apy[i].rank;
		admit.push_back(apy[i].id);
		return true;
	}
	return false;
}

void Apy::Handle(int K,int loc)
{
	Fin(i, 0, K - 1)
		if (school[choice[i]].Admit(loc))
			break;
}

int N, M, K;
void CalRank() {
	apy[0].rank = 1;
	Fin(i, 1, N - 1) {
		if (apy[i].GF == apy[i - 1].GF && apy[i].GE == apy[i - 1].GE)
			apy[i].rank = apy[i - 1].rank;
		else
			apy[i].rank = apy[i - 1].rank + 1;
	}
#ifdef DEBUG
	Fin(i, 0, N - 1)
		apy[i].Display(K);
#endif // DEBUG

}

void Init() {
	Fin(i, 0, M - 1) {
		school[i].minRank = -1;
		school[i].cnt = 0;
		SfI(school[i].quoto);
	}
	Fin(i, 0, N - 1) 
		apy[i].Scan(i,K);
	sort(apy, apy + N);
	CalRank();
}
void Handle() {
	Fin(i, 0, N - 1)
		apy[i].Handle(K, i);
}
void Display() {
	Fin(i, 0, M - 1)
		school[i].Display();
}
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	while (~scanf("%d %d %d", &N, &M, &K)) {
		Init();
		Handle();
		Display();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
