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

#define MAXN_PLAYER 10500
#define MAXN_TABLE  120
#define NIL -1
struct Time {
	int hh, mm, ss, v;
	Time(){}
	Time(int h, int m, int s):hh(h),mm(m),ss(s) {
		ToSecond();
	}
	Time(int x) {
		Scan(x);
	}
	void Scan() {
		scanf("%d%*c%d%*c%d", &hh, &mm, &ss);
		ToSecond();
	}
	void Scan(int x) {
		v = x;
		FormatTime(x);
	}
	void Print() {
		printf("%02d:%02d:%02d", hh, mm, ss);
	}
	void ToSecond() {
		v = ss + (mm + hh * 60) * 60;
	}
	void FormatTime(int x) {
		ss = x % 60; x /= 60;
		mm = x % 60; x /= 60;
		hh = x;
	}
};
const Time ENDTIME(21, 0, 0);
const Time STATIME(8, 0, 0);
struct Table {
	bool vipFlag;
	int serverCnt, endTime;
	void Init() {
		vipFlag = false;
		serverCnt = 0; endTime = STATIME.v;
	}
};
struct Player {
	Time arriveTime, serverTime;
	int playTime, isVIP;
	bool isServered;
	void Scan() {
		arriveTime.Scan();
		SfI(playTime);
		playTime = min(120, playTime); // 防止数据坑人
		SfI(isVIP);
		isServered = false;
	}
	void Print() {
		if (!isServered)
			return;
		arriveTime.Print(); putchar(' ');
		serverTime.Print(); putchar(' ');
		int wait = (serverTime.v - arriveTime.v) / 60;
		wait += ((serverTime.v - arriveTime.v) % 60 >= 30) ? 1 : 0;
		printf("%d\n", wait);
	}
	bool operator<(const Player & A)const {
		return arriveTime.v < A.arriveTime.v;
	}
}players[MAXN_PLAYER];
struct Club {
	Table tables[MAXN_TABLE];
	int totTablesNum, vipTablesNum;
	void Init() {
		SfI(totTablesNum);
		Fin(i, 0, totTablesNum - 1)
			tables[i].Init();
		SfI(vipTablesNum);
		int tableId;
		Fin(i, 0, vipTablesNum - 1) {
			SfI(tableId);
			tables[tableId - 1].vipFlag = true;
		}
	}
	void Process(int t, int x) { // t号桌子，第x对
#ifdef DEBUG
		printf("player %d at %d table, time is \n", x, t);
#endif // DEBUG
		++tables[t].serverCnt;
		if (tables[t].endTime <= players[x].arriveTime.v)	// 用户来时为空
			tables[t].endTime = players[x].arriveTime.v;
		players[x].serverTime.Scan(tables[t].endTime);// 确定被服务时间
#ifdef DEBUG
		players[x].Print();
#endif // DEBUG
		tables[t].endTime += players[x].playTime * 60;			// 更新下次桌子空闲时间
		players[x].isServered = true;
	}
	int tableEmpty[MAXN_TABLE], cntEmpty;
	int GetTableCanServer() {	// 返回最先空闲的桌子
		int minTime = tables[0].endTime;
		cntEmpty = 0;
		tableEmpty[cntEmpty++] = 0;
		Fin(i, 1, totTablesNum - 1) {
			if (tables[tableEmpty[0]].endTime > tables[i].endTime) {
				cntEmpty = 0;
				tableEmpty[cntEmpty++] = i;
			}	
			if (tables[tableEmpty[0]].endTime == tables[i].endTime) {
				tableEmpty[cntEmpty++] = i;
			}
			//	id = i;
		}
		return cntEmpty;
	}
}club;
int NumOfPlayer;
queue<int> allPlayerQueue, vipPlayerQue;
void Handle() {
	sort(players, players + NumOfPlayer); // 先按照到达时间排序
	while (!allPlayerQueue.empty()) 
		allPlayerQueue.pop();
	while (!vipPlayerQue.empty()) 
		vipPlayerQue.pop();
	int cnt = 0, cntEmpty, neverInQue = 0;
	while (cnt < NumOfPlayer) {
		cntEmpty = club.GetTableCanServer();
#ifdef DEBUG
		printf("______POCCESS %d_______\n", cnt);
		printf("table %d is empty for server, time is ", tableID);
		Time(club.tables[tableID].endTime).Print(); putchar('\n');
#endif // DEBUG
		if (club.tables[club.tableEmpty[0]].endTime >= ENDTIME.v)
			break;
		if (allPlayerQueue.empty() && neverInQue < NumOfPlayer
				&& club.tables[club.tableEmpty[0]].endTime < players[neverInQue].arriveTime.v) { // 队列为空，之前的都被服务过了
			// 下面的做法确保了，等下一个服务对象到来的时候，服务的桌子编号最小，而且确保同时到达的VIP能拿到专属VIP且唯一空闲桌子
			// 而且确保了，不会等到服务一个明明是闭关后到达的用户，见下面被注释的代码，它却不论到达时间都服务了
			Fin(i, 0, cntEmpty - 1)
				club.tables[club.tableEmpty[i]].endTime = players[neverInQue].arriveTime.v;
			continue;
		}
		while (neverInQue < NumOfPlayer && players[neverInQue].arriveTime.v <= club.tables[club.tableEmpty[0]].endTime) {
			allPlayerQueue.push(neverInQue);
			if(players[neverInQue].isVIP)
				vipPlayerQue.push(neverInQue);
			++neverInQue;
		}
		/*
		if (allPlayerQueue.empty()) { // 队列为空，之前的都被服务过了
			club.Process(tableID, neverInQue);
			++neverInQue;
			++cnt;
			continue;
		}
		*/
		int playId = NIL;
		while (!allPlayerQueue.empty()) {	// 清空冗余
			if (!players[allPlayerQueue.front()].isServered)
				break;
			allPlayerQueue.pop();
		}
		while (!vipPlayerQue.empty()) {		// 清空冗余
			if (!players[vipPlayerQue.front()].isServered)
				break;
			vipPlayerQue.pop();
		}
		int vipTable = NIL;
		Fin(i, 0, cntEmpty - 1) if (club.tables[club.tableEmpty[i]].vipFlag) {
			vipTable = club.tableEmpty[i];
			break;
		}
		if (~vipTable && !vipPlayerQue.empty()) { // VIP桌空且队列里有VIP
			playId = vipPlayerQue.front();
			vipPlayerQue.pop();
			club.Process(vipTable, playId);
			++cnt;
			continue;
		}
		// 否则都是普通成员处理
		while (!allPlayerQueue.empty()) {
			playId = allPlayerQueue.front();
			allPlayerQueue.pop();
			if (players[playId].isServered) // 已经被提前服务过的VIP
				continue;
			break;
		}
		if (~playId) {
			club.Process(club.tableEmpty[0], playId);
			++cnt;
		}
	}
}
bool MyCmp(const Player & A, const Player & B) {
	if (A.isServered != B.isServered)
		return A.isServered > B.isServered;
	return A.serverTime.v < B.serverTime.v;
}
void Print() {
	
	sort(players, players + NumOfPlayer, MyCmp);
	Fin(i, 0, NumOfPlayer - 1)
		players[i].Print();
	Fin(i, 0, club.totTablesNum - 1)
		printf("%d%c", club.tables[i].serverCnt, i != club.totTablesNum - 1 ? ' ' : '\n');
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	//freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI(NumOfPlayer)) {
		Fin(i, 0, NumOfPlayer - 1)
			players[i].Scan();
		club.Init();
		Handle();
#ifdef DEBUG
		printf("____________________RES__________________\n");
#endif // DEBUG
		Print();
	}
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解： 坑无限多，超级多，超级多！ 为啥VIP一定要坐VIP桌子，NC么？？？？
