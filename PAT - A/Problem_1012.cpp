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
#define SfLL(x) scanf("%lld",x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG
#define MAXN 2050
#define NIL -1

map<string, int> idHash;
map<string, int> :: iterator it;

struct Rec {
	int id, rank;
	double score;
	bool operator<(const Rec & A) const {
		return score > A.score;
	}
}grades[4][MAXN];
struct Stu {
	int bestRank, courses;
}stu[MAXN];
int N, M;
void Init() {
	string id;
	double tot;
	Fin(i, 0, N - 1) {
		cin >> id;
		idHash[id] = i;
		stu[i].bestRank = N + 1;
		tot = 0;
		Fin(j, 1, 3) {
			grades[j][i].id = i;
			SfD(grades[j][i].score);
			tot += grades[j][i].score;
		}
		grades[0][i].id = i;
		grades[0][i].score = tot;
	}
	Fin(i, 0, 3) {
		sort(grades[i], grades[i] + N);
		grades[i][0].rank = 1;
		Fin(j, 1, N - 1) { 
			if (grades[i][j].score == grades[i][j - 1].score)
				grades[i][j].rank = grades[i][j-1].rank;
			else
				grades[i][j].rank = j + 1; // error 重置为j + 1才对！排名算法要熟悉
		}
		Fin(j, 0, N - 1) if (stu[grades[i][j].id].bestRank > grades[i][j].rank) {
			stu[grades[i][j].id].bestRank = grades[i][j].rank;
			stu[grades[i][j].id].courses = i;
		}
	}
}
char letter[] = "ACME";
void Handle() {
	string id;
	cin >> id;
	if ((it = idHash.find(id)) == idHash.end())
		printf("N/A\n");
	else {
		printf("%d %c\n",stu[it->second].bestRank, letter[stu[it->second].courses]);
	}
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, M)) {
		Init();
		Fin(i, 1, M)
			Handle();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
