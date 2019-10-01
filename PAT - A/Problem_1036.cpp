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

#define MAXN 20
#define NIL -1
struct Rec {
	string name, id;
	void ReNew(string a, string b) {
		name = a;
		id = b;
	}
}boy, girl;
int boyLost, girlBest, N, score;
char name[MAXN], id[MAXN], gender;
void Handle() {
	if (gender == 'M' && score < boyLost) {
		boyLost = score;
		boy.ReNew(name, id);
	}
	else if (gender == 'F' && score > girlBest) {
		girlBest = score;
		girl.ReNew(name, id);
	}
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(N)) {
		boyLost = INT_MAX;
		girlBest = -1;
		Fin(i, 1, N) {
			scanf("%s%*c%c%*c%s%*c%d", name, &gender, id, &score);
			//printf("%s %c %s %d\n", name, gender, id, score);
			Handle();
		}
		if (girlBest == -1)
			printf("Absent\n");
		else
			cout << girl.name << ' ' << girl.id << endl;
		if (boyLost == INT_MAX)
			printf("Absent\n");
		else
			cout << boy.name << ' ' << boy.id << endl;
		if (girlBest != -1 && boyLost != INT_MAX)
			printf("%d\n", girlBest - boyLost);
		else
			printf("NA\n");
	}

#ifdef DEBUG
	//while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
