#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#include <stack>
#include <map>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

#define MAXN 120
#define NIL	-1

struct Obj{
	int len;
	char str[300];
}rec[MAXN];
int N, minLen;
bool Judge(int dis) {
	char patten = rec[0].str[rec[0].len - dis - 1];
	Fin(i, 1, N-1) {
		if (patten != rec[i].str[rec[i].len - dis - 1]) {
			return false;
		}
	}
	return true;
}
int Cal() {
	Fin(i, 1, 300) {
		if (minLen < i)
			return i - 1;
		if (!Judge(i - 1))
			return i - 1;
	}
	return 300;
}

char None[300];
int main() {
	//freopen("e:\\test.txt","r",stdin);
	while (~SfI(N)) {
		cin.getline(None, 300);
		minLen = INT_MAX;
		Fin(i, 0, N - 1) {
			cin.getline(rec[i].str,300);
			rec[i].len = strlen(rec[i].str);
			minLen = min(minLen, rec[i].len);
		}
		int start = rec[0].len - Cal();
		while (rec[0].str[start] == ' ')
			++start;
		if (rec[0].len - start)
			puts(rec[0].str + start);
		else
			puts("nai");
	}
	//while (1);
	return 0;
}

// 题解：
