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
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG

#define MAXN 100500
#define NIL -1
struct Rec{
	int a, b;
	void Init(){
		SfI2(a, b);
	}
}rec[10050];
int N, M;
void Init(){
	Fin(i,1,N)
		rec[i].Init();
}
int K;
bool exist[MAXN];
bool Judge(){
	memset(exist, false, sizeof exist);
	int x;
	Fin(k, 1, K)
		SfI(x), exist[x] = true;
	Fin(i,1,N)
		if(exist[rec[i].a] && exist[rec[i].b])
			return false;
	return true;
}
int main(void){
#ifdef DEBUG
	freopen("d:\\test.txt","r",stdin);
	//freopen("d:\\tsst.txt","w",stdout);
#endif
	while(~SfI2(N, M)){
		Init();
		Fin(i,1,M){
			SfI(K);
			printf("%s\n", Judge()?"Yes":"No");
		}
	}
#ifdef DEBUG
	while(1);
#endif
	return 0;
}
