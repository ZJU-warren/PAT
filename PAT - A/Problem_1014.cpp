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
#define MAXN_QUEUE 25
#define MAXN_CLIENT 1200
#define NIL -1
const int BASE_HOUR = 8;
const int BASE_MINU = 0;
void ShowTime(int minutes) {
	printf("%02d:%02d\n", minutes / 60 + BASE_HOUR, minutes % 60 + BASE_MINU);
}
struct Client {
	int endTime, transTime;
	void Print() {
		if (endTime - transTime < 540)
			ShowTime(endTime);
		else
			printf("Sorry\n");
	}
}client[MAXN_CLIENT];

struct Bank{
	queue<int> Q[MAXN_QUEUE];
	int queueTime[MAXN_QUEUE];
	int size;
	void Init(int s) {
		size = s;
		Fin(i, 1, size) {
			while (!Q[i].empty())
				Q[i].pop();
			queueTime[i] = 0;
		}
	}
	int GetNext() {
		int queueId, clientId, minTime = INT_MAX;
		Fin(i, 1, size) if (!Q[i].empty()) { // 找到将最先处理结束当前客户的窗口
			clientId = Q[i].front();
			if (client[clientId].transTime + queueTime[i] < minTime) {
				minTime = client[clientId].transTime + queueTime[i];
				queueId = i;
			}
		}
		clientId = Q[queueId].front();
		Q[queueId].pop();
		queueTime[queueId] = client[clientId].endTime = client[clientId].transTime + queueTime[queueId];
#ifdef DEBUG
		printf("clinet %d is end at %d\n", clientId, queueTime[queueId]);
#endif // DEBUG
		return queueId;
	}
	void Insert(int queId, int clientId) {
		Q[queId].push(clientId);
#ifdef DEBUG
		printf("--------insert client %d to queue %d\t", clientId, queId);
		printf("now it's size is %d\n", Q[queId].size());
#endif // DEBUG
	}
}bank;

int N, M, K, Q;
void Handle() {
	bank.Init(N);
	// 先完全填充
	int num = min(K, N*M);
	Fin(i, 1, num) {
		bank.Insert(i % N ? i % N : N, i);
	}
	// 依次处理
	int nxQueEmptyId;
	Fin(i, 1, K) {
		nxQueEmptyId = bank.GetNext();
		if (num < K)
			bank.Insert(nxQueEmptyId, ++num);
	}
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, M)) {
		SfI2(K, Q);
		Fin(i, 1, K)
			SfI(client[i].transTime);
		Handle();
		int id;
		Fin(q, 1, Q) {
			SfI(id);
			client[id].Print();
		}
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 
