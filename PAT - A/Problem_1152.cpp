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
#define MAXN 2000

//#define DEBUG

bool IsPrime(LL x){
	if(x < 2)
		return false;
	if(x == 2)
		return true;
	//printf("x == %lld\n",x);
	for(LL i = 2; i*i > 0 && i*i <= x; ++i){
		if(x % i == 0){
			//printf("i == %lld\n",i);
			return false;
		}
	}
	return true;
}

char str[MAXN],strTemp[MAXN];
int K,SL;
void Find(){
	LL temp;
	SfI2(SL,K);
	SfS(str);
	bool flag = false;
	int len = strlen(str);
	Fin(i,0,len-K){
		strncpy(strTemp,str+i,K);
		strTemp[K] = 0;
		sscanf(strTemp,"%lld",&temp);
		//printf("%lld\n",temp);
		if(IsPrime(temp)){
			flag = true;
			puts(strTemp);
			return;
		}
	}
	if(!flag)
		puts("404");	
}
int main(void){
#ifdef DEBUG
	freopen("D:\\test.txt","r",stdin);
	//freopen("D:\\tsst.txt","w",stdout);
#endif 
	Find();
	return 0;
}
