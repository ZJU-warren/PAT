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

#define MAX_PEO 10500
#define MAX_WIN 200
#define NIL -1
const int START_TIME = 8 * 60 * 60;
const int END_TIME = 17 * 60 * 60;
int getTime() {
	int hh, mm, ss;
	scanf("%d%*c%d%*c%d", &hh, &mm, &ss);
	return (hh * 60 + mm) * 60 + ss;
}
struct Peo {
	int arriveTime, serverTime, needs;
	bool operator<(const Peo &A) const{			// 注意两个const
		return arriveTime < A.arriveTime;
	}
}peo[MAX_PEO];

struct Win {
	int endTime;
	Win(int e):endTime(e){}
	Win(){}
	bool operator<(const Win &A) const {
		return endTime > A.endTime;
	}
	void Server(int i) {
		if (endTime <= peo[i].arriveTime) {
			endTime = peo[i].arriveTime + peo[i].needs*60;
			peo[i].serverTime = peo[i].arriveTime;
		}
		else {
			peo[i].serverTime = endTime;
			endTime += peo[i].needs*60;
		}
	}
};
int N, K;
void Init() {
	int cnt = 0;
	Fin(i,1,N){
		peo[cnt].arriveTime = getTime();
		SfI(peo[cnt].needs);
		if (peo[cnt].arriveTime < END_TIME)
			++cnt;
	}
	N = cnt;
	sort(peo, peo + N);
}

priority_queue<Win> Q;
double Handle() {
	Fin(i, 1, K)
		Q.push(Win(START_TIME));
	Win w;
	Fin(i, 0, N-1) {
		w = Q.top();
		Q.pop();
		w.Server(i);
		Q.push(w);
	}
	int tot = 0;
	Fin(i, 0, N-1)
		tot += peo[i].serverTime - peo[i].arriveTime;
	return (double)tot / N;
}

int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, K)) {
		Init();
		printf("%.1lf\n", Handle()/60);
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
