#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

//#define DEBUG

#define MAXN 1100000
#define NIL	-1

struct Obj {
	char str[MAXN], word[MAXN];
	int p, lenStr, lenWord;
	void Scan() {
		cin.getline(str, MAXN);
		lenStr = strlen(str);
		p = 0;
	}
	bool Format(char & x) {
		if ('A' <= x && x <= 'Z')
			x = x - 'A' + 'a';
		return 'a' <= x && x <= 'z' || '0' <= x && x <= '9';
	}
	bool GetNext() {
		while (p < lenStr && !Format(str[p]))
			++p;
		lenWord = 0;
		while (p < lenStr && Format(str[p])) {
			word[lenWord++] = str[p];
			++p;
		}
		word[lenWord] = 0;
		return lenWord != 0;
	}
}obj;


struct Rec {
	string str;
	int num;
	bool operator < (const Rec & A) {
		if (num != A.num)
			return num > A.num;
		return str > A.str;
	}
}rec[MAXN/2];
int cnt = 0;
map<string, int> M;
map<string, int> ::iterator it;
int main() {
#ifdef DEBUG
	freopen("e:\\test.txt", "r", stdin);
#endif // DEBUG
	M.clear();
	obj.Scan();
	while (obj.GetNext())
		++M[obj.word];
	for (it = M.begin(); it != M.end(); ++it) {
		rec[cnt].str = it->first;
		rec[cnt].num = it->second;
		++cnt;
	}
	sort(rec, rec + cnt);
	cout << rec[0].str << " " << rec[0].num << endl;
#ifdef DEBUG
	while (1);
#endif // DEBUG
	return 0;
}

// 题解：
