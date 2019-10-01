#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <map>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfLL(x) scanf("%lld",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

#define MAXN 100500
#define NIL	-1

LL arr[MAXN],p;
int N;
int UpperSearch(LL key) {
	int lef = 0, rig = N, mid;
	while (lef < rig) {
		mid = (lef + rig) / 2;
		if (arr[mid] > key)
			rig = mid;
		else
			lef = mid + 1;
	}
	return lef;
}
int Cal() {
	int cnt = 0;
	Fin(i, 0, N - 1) {
		/*if (arr[i] * p > arr[N - 1])
			break;*/
		cnt = max(cnt, UpperSearch(arr[i] * p) - i);
	}
	return cnt;
}
int main()
{
	//freopen("e:\\test.txt","r",stdin);
	while (~scanf("%d %lld", &N, &p)) {
		Fin(i, 0, N - 1)
			SfLL(arr[i]);
		sort(arr, arr + N);
		cout << Cal() << endl;
	}
	return 0;
}
// 题解：
