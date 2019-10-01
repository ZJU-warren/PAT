#include <bits/stdc++.h>

using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define SfI(x) scanf("%d",&x)
#define SfS(x) scanf("%s",x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;

#define MAXN 155
#define EMPTY 500

struct Obj {
	int id;
	char letter;
	Obj() { id = EMPTY; }
	bool operator < (const Obj & A) const {
		return id < A.id;
	}
	void Set(int i, int l) {
		if(id == EMPTY)
			id = i;
		letter = l;
	}
}record[MAXN];

int cntR;
char a[MAXN],b[MAXN];

int Encode(char &x) {
	return 'A' <= x && x <= 'Z' ? x - 'A' + 10 : x - '0';
}
void Format(char &x) {
	x = 'a' <= x && x <= 'z' ? x - 'a' + 'A' : x;
}
int Init() {
	if (!(~SfS(a))) {
		return -1;
	}
	SfS(b);
	cntR = 0;
	int pb = 0;
	int lena = strlen(a), lenb = strlen(b);
	Fin(i, 0, lena-1) {
		Format(a[i]);
		Format(b[pb]);
		if (a[i] == b[pb])
			++pb;
		else {
			record[Encode(a[i])].Set(i, a[i]);
		}
	}
	return 0;
}
int main()
{
	//freopen("e:\\test.txt","r",stdin);
	while (~Init()) {
		sort(record, record + MAXN);
		int i = 0;
		while (record[i].id != EMPTY)
			putchar(record[i++].letter);
		putchar('\n');
	}
	return 0;
}
// 题解：水题，要更快！

