#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <cstdlib>
#include <climits>
#include <stack>
#include <algorithm>
using namespace std;

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define Fde(i,f,t) for(int i = f; i >= t; --i)
#define SfI(x) scanf("%d",&x)
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 120
#define NIL -1

int bestRes[5], res[5], stat[MAXN], N;
void Init(){
	Fin(i,1,N)
		SfI(stat[i]);
}
int isHuman[MAXN];
bool visit[MAXN];
bool JudgeLier(int a, int b){
	memset(isHuman, 0xff, sizeof isHuman);
	memset(visit, false, sizeof visit);
	int st, choice;
	Fin(i, 1, N){
		choice = abs(stat[i]);
		if(i != a && i != b)
			st = stat[i] > 0? 1 : 0;
		else
			st = stat[i] > 0? 0 : 1;
		if(~isHuman[choice] && isHuman[choice] != st){
			return false;
		}
		isHuman[choice] = st;
	}
	int cnt = 0;
	Fin(i, 1, N) if(!visit[i] && !isHuman[i]){
		visit[i] = true;
		res[++cnt] = i;
	}
	if(cnt > 2) return false;
	if(cnt == 2){
		if(res[1] > res[2])
			swap(res[1], res[2]);
		if(a > b)
			swap(a, b);
		if(a == res[1] && b != res[2])
			return true;
		if(a != res[1] && b == res[2])
			return true;
		return false;
	}
	if(cnt < 2){
		Fin(i, 1, N) if(!visit[i] && isHuman[i] == NIL){
			visit[i] = true, res[++cnt] = i;
			break;
		}
	}
	if(cnt != 2)
		return false;
	if(res[1] > res[2])
		swap(res[1], res[2]);
	if(a > b)
		swap(a, b);
	if(a == res[1] && b != res[2])
		return true;
	if(a != res[1] && b == res[2])
		return true;
	return false;
}
int main(void){
#ifdef DEBUG
	freopen("d:\\test.txt","r",stdin);
	//freopen("d:\\tsst.txt","w",stdout);
#endif
	bool flag;
	while(~SfI(N)){
		bestRes[1] = N + 20;
		Init();
		flag = false;
		Fin(i,1,N) Fin(j,i+1,N){
			if(JudgeLier(i,j)){
				flag = true;
				if(res[1] < bestRes[1]){
					bestRes[1] = res[1];
					bestRes[2] = res[2];
				}
				else if(res[1] == bestRes[1] && bestRes[2] > res[2]){
					bestRes[2] = res[2];
				}
			}
		}
		if(!flag)
			printf("No Solution\n");
		else
			printf("%d %d\n", bestRes[1], bestRes[2]);
	}
#ifdef DEBUG
	while(1);
#endif
	return 0;
}
