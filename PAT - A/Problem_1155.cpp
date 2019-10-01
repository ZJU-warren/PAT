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
int tree[MAXN];
int N;

void Init(){
	SfI(N);
	Fin(i,1,N){
		SfI(tree[i]);
	}
}
bool maxHeap,minHeap;
int path[MAXN], cntP;
void NRL(int id, int deep){
	path[deep] = tree[id];
	if(id * 2 + 1 <= N){
		if(tree[id] < tree[id * 2 + 1]) maxHeap = false;
		if(tree[id] > tree[id * 2 + 1]) minHeap = false;
		NRL(id * 2 + 1,deep + 1);
	}
	if(id * 2 <= N){
		if(tree[id] < tree[id * 2]) maxHeap = false;
		if(tree[id] > tree[id * 2]) minHeap = false;
		NRL(id * 2 ,deep + 1);
	}
	if(id * 2 > N){
		Fin(i,1,deep)
			printf("%d%c",path[i],i==deep?'\n':' ');
	}
}
int main(void){
#ifdef DEBUG
	freopen("D:\\test.txt","r",stdin);
	//freopen("D:\\tsst.txt","w",stdout);
#endif 
	Init();
	maxHeap = true,minHeap = true;
	NRL(1,1);
	if(maxHeap == true)
		printf("Max Heap\n");
	else if(minHeap == true)
		printf("Min Heap\n");
	else
		printf("Not Heap\n");
	
#ifdef DEBUG
	while(1);
#endif 
	return 0;
}
