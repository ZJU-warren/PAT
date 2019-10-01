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

struct Edge{
	int a,b;
	void Scan(){
		SfI2(a,b);
	}
}edge[MAXN];
int vex[MAXN];
set<int> S;

int N,M;
void Init(){
	SfI2(N,M);
	Fin(i,1,M)
		edge[i].Scan();
}
void Judge(){
	S.clear();
	Fin(i,0,N-1){
		SfI(vex[i]);
		S.insert(vex[i]);
	}
	bool flag = true;
	Fin(i,1,M){
		if(vex[edge[i].a] == vex[edge[i].b]){
			flag = false;
			break;
		}
	}
	if(!flag)
		printf("No\n");
	else
		printf("%d-coloring\n",(int)S.size());
}
int main(void){
#ifdef DEBUG
	freopen("D:\\test.txt","r",stdin);
	//freopen("D:\\tsst.txt","w",stdout);
#endif 
	Init();
	int K;
	SfI(K);
	Fin(k,1,K){
		Judge();
	}
#ifdef DEBUG
	while(1);
#endif 
	return 0;
}
