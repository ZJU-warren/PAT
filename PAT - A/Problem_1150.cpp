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
#define SfI2(x, y) scanf("%d %d",&x, &y)
#define SfI3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 250
#define NIL -1

int mat[MAXN][MAXN], N, M;
void Init(){
	int f, t, dis;
	Fin(i,1,N) Fin(j,1,N) 
		mat[i][j] = -1;
	Fin(i,1,N) 
		mat[i][i] = 0;
	Fin(i,1,M){
		SfI3(f, t, dis);
		mat[f][t] = mat[t][f] = dis;
	}
}
int path[MAXN*100], len;
int visit[MAXN];
int bestResId, bestLen, resLen;
int Judge(int id){
	memset(visit, 0, sizeof visit);
	resLen = 0;
	++visit[path[1]];
	Fin(i,2,len){
		++visit[path[i]];
		if(mat[path[i-1]][path[i]] == NIL)
			return -1;
		resLen += mat[path[i-1]][path[i]];
	}
	if(path[1] != path[len])
		return 0;
	Fin(i,1,N) if(!visit[i]){
		return 0;
	}
	bool con = false;
	if(visit[path[1]] > 2)
		con = true;
	else{
		Fin(i,1,N) if(visit[i] > 1 && i != path[1])
			con = true;
	}
	if(bestLen > resLen){
		bestResId = id;
		bestLen = resLen;
	}
	return con? 1 : 2;
}
int main(void){
#ifdef DEBUG
	freopen("d:\\test.txt","r",stdin);
	freopen("d:\\tsst.txt","w",stdout);
#endif
	int P, res;
	while(~SfI2(N, M)){
		bestLen = 0x3f3f3f3f;
		Init();
		SfI(P);
		Fin(i, 1, P){
			SfI(len);
			Fin(i,1,len)
				SfI(path[i]);
			res = Judge(i);
			if(res == -1)
				printf("Path %d: NA (Not a TS cycle)\n", i);
			else if(!res)
				printf("Path %d: %d (Not a TS cycle)\n", i, resLen);
			else if(res == 1)
				printf("Path %d: %d (TS cycle)\n", i, resLen);
			else
				printf("Path %d: %d (TS simple cycle)\n", i, resLen);
		}
		printf("Shortest Dist(%d) = %d\n",bestResId, bestLen);
	}
#ifdef DEBUG
	//while(1);
#endif
	return 0;
}
