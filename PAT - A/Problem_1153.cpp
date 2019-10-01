#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)
#define SfD(x) scanf("%lf",&x)
#define SfLL(x) scanf("%lld",&x)
#define SfC(x) scanf("%c",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
typedef long long LL;

#define NIL -1
#define MAXN 20000

//#define DEBUG

struct Rec{
	int level, site, date, id, score;
	char str[20];
	void Clear(){
		level = site = date = id = score = -1;
	}
	void Init(){
		SfS(str);
		char strTemp[20];
		if(str[0] == 'B') level = 3;
		else if(str[0] == 'A') level = 1;
		else level = 2;
		strncpy(strTemp, str + 1, 3); strTemp[3] = 0;
		sscanf(strTemp,"%d",&site);
		strncpy(strTemp, str + 4, 6); strTemp[6] = 0;
		sscanf(strTemp,"%d",&date);
		strncpy(strTemp, str + 10, 3); strTemp[3] = 0;
		sscanf(strTemp,"%d",&id);
		SfI(score);
	}
}rec[MAXN];

struct Site{
	int num, id;
	bool operator <(const Site & A) const{
		if(num != A.num)
			return num > A.num;
		return id < A.id;
	}
}TestSite[MAXN];

bool CmpT1(const int & A, const int & B){
	if(rec[A].level != rec[B].level)
		return rec[A].level < rec[B].level;
	if(rec[A].score != rec[B].score)
		return rec[A].score > rec[B].score;
	return strcmp(rec[A].str, rec[B].str) < 0;
}
int t1[MAXN];
int N,M;
void Init(){
	Fin(i,0,MAXN-1)
		rec[i].Clear(),t1[i] = i;
	SfI2(N,M);
	Fin(i,0,N-1){
		rec[i].Init();
		
	}
	sort(t1, t1+N, CmpT1);
}

void Query3(int key){
	Fin(i,0,MAXN-1)
		TestSite[i].num = 0, TestSite[i].id = i;
	Fin(i,0,N-1) if(rec[i].date == key){
		++TestSite[rec[i].site].num;
	}
	sort(TestSite,TestSite+MAXN);
	bool flag = false;
	Fin(i,0,MAXN-1){
		if(TestSite[i].num == 0) break;
		flag = true;
		printf("%d %d\n",TestSite[i].id,TestSite[i].num);
	}
	if(!flag) printf("NA\n");
}
void Query2(int key){
	bool flag = false;
	LL sum = 0, numS = 0;
	Fin(i,0,MAXN-1) if(rec[i].site == key){
		flag = true;
		++numS;
		sum += rec[i].score;
	}
	if(!flag) printf("NA\n");
	else
		printf("%lld %lld\n",numS,sum);
}
void Query1(int key){ 
	bool flag = false;
	Fin(i,0,MAXN-1) if(rec[t1[i]].level == key){
		flag = true;
		printf("%s %d\n",rec[t1[i]].str,rec[t1[i]].score);
	}
	if(!flag) printf("NA\n");
}
int main(void){
#ifdef DEBUG
	freopen("D:\\test.txt","r",stdin);
#endif 
	Init();
	int query, key;
	char letter;
	Fin(i,1,M){
		SfI(query);
		if(query == 2){
			SfI(key);
			printf("Case %d: %d %d\n", i, query, key);
			Query2(key);
		}
		else if(query == 3){
			SfI(key);
			printf("Case %d: %d %06d\n", i, query, key);
			Query3(key);
		}
		else{
			scanf("%*c%c",&letter);
			if(letter == 'B') key = 3;
			else if(letter == 'A') key = 1;
			else if(letter == 'T') key = 2;
			else key = 99999;
			printf("Case %d: %d %c\n", i, query, letter);
			Query1(key);
		}
	}

#ifdef DEBUG
	while(1);
#endif 
	return 0;
}
