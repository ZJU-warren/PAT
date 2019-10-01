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
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

#define MAXN 1055
#define NIL	-1

char str[MAXN];
map<char, int> shoper, eva;
map<char, int>::iterator it;
int totNumShoper, totNumEva;

void Init() {
	shoper.clear();
	eva.clear();
	totNumShoper = strlen(str);
	Fin(i, 0, totNumShoper - 1)
		++shoper[str[i]];
	SfS(str);
	totNumEva = strlen(str);
	Fin(i, 0, totNumEva - 1)
		++eva[str[i]];
}
void Cal() {
	int dis = 0,loss;
	char now;
	for (it = eva.begin(); it != eva.end(); ++it) {
		now = it->first;
		loss = shoper[now] - it->second;
		//printf("%c - %d\n", now, loss);
		if (loss < 0)
			dis += -loss;
	}
	if (dis)
		printf("No %d\n", dis);
	else
		printf("Yes %d\n", totNumShoper - totNumEva);
}
int main()
{
	//freopen("e:\\test.txt","r",stdin);
	while (~SfS(str)) {
		Init();
		Cal();
	}
	return 0;
}
// 题解：ppRYYGrrYBR2258 YrR8RrY
