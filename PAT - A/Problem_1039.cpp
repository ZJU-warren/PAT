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

#define MAXN_V (26 * 26 * 26 * 10 + 50)	// error3 : 大小估计根据ID特征，又错了一次，难受
#define MAXN_E 2550
#define MAXN_IN 210
#define NIL -1

struct V {
	int first;
}vex[MAXN_V];
struct E {
	int f, t, next;
}edge[MAXN_E * MAXN_IN];
int cntE, N, K;
void AddEdge(int f, int t) {
	edge[cntE].t = t;
	edge[cntE].f = f;
	edge[cntE].next = vex[f].first;
	vex[f].first = cntE++;
}
struct MyString {
	char str[6];
};
bool hashTable[MAXN_V];
int GetID(MyString x) {	
// error1 : 居然卡总共Nlog2N的离散化，没得天理了已经
// error2 : 映射又错了一次，难受
	//printf("MAX ID is %d\n", MAXN_V-1);
	int res = x.str[3] - '0';
	Fde(i, 2, 0)
		res = res * 26 + x.str[i] - 'A';
	return res;
}
void Init() {
	cntE = 0;		
	memset(hashTable, false, sizeof hashTable);
	MyString name;
	int courseID, nStu, stuID;
	Fin(i, 1, K) {
		SfI2(courseID, nStu);
		Fin(j, 1, nStu) {
			SfS(name.str);
			stuID = GetID(name);
			if (!hashTable[stuID]) {
				//printf("%s is %d\n", name.str, stuID);
				vex[stuID].first = NIL;
				hashTable[stuID] = true;
			}
			AddEdge(stuID, courseID);
		}
	}
}
int cntCourse, que[MAXN_E]; // error : que应该是所有课程的总数
void Print(int u) {
	cntCourse = 0;
	for (int i = vex[u].first; ~i; i = edge[i].next) {
		que[cntCourse++] = edge[i].t;
	}
	sort(que, que + cntCourse);
	printf("%d", cntCourse);
	Fin(i, 0, cntCourse - 1)
		printf(" %d", que[i]);		
}
int main(void) {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
	freopen("e:\\tsst.txt", "w", stdout);
#endif // DEBUG
	while (~SfI2(N, K)) {
		Init();
		MyString name;
		int stuID;
		Fin(i,1,N){
			SfS(name.str);
			printf("%s ", name.str);
			stuID = GetID(name);
			if(!hashTable[stuID])
				putchar('0');
			else
				Print(stuID);
			putchar('\n');
		}
	}
#ifdef DEBUG
	//while (1);
#endif // DEBUG
	return 0;
}

// 题解：用map离散化的时候注意不要映射到0上，因为map[key] = 0被用判空
// error : 开数组一定要注意数量
// error : 是的，居然卡map映射的Nlog2N，真的没天理
