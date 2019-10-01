#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

#define Fin(i,f,t) for(int i=f; i<=t; ++i)
#define Fde(i,f,t) for(int i=f; i>=t; --i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d %d",&x,&y)
typedef long long LL;


const int MAXN = 1 << 16;

bool num[MAXN];
int  prime[MAXN],cntPrime = 0;
void Seive() {
	memset(num, false, sizeof num);
	Fin(i, 2, MAXN - 1) if (!num[i]) {
		prime[++cntPrime] = i;
		for (LL j = (LL)i * i; j <= MAXN - 1; j += i)
			num[j] = true;
	}
}


bool IsPrime(int N) {
	Fin(i, 1, cntPrime){
		if (N <= prime[i])
			break;
		if (!(N%prime[i])) 
			return false;
	}
	return true;
}

int numDiv[MAXN];
int tmpDiv[MAXN];
int maxCon, maxConStart;

int Handle(int len) {
	int p = 0;
	// distiguish each elem
	tmpDiv[++p] = numDiv[1];
	Fin(i, 2, len) if (numDiv[i] != tmpDiv[p])
		tmpDiv[++p] = numDiv[i];
	// cal con
	int startId = 1, maxcont = 1,maxstartId = 1;
	tmpDiv[p + 1] = -1;
	Fin(i, 2, p+1) if (tmpDiv[i] != tmpDiv[i - 1] + 1) {
		if (maxcont < i - startId) {
			maxcont = i - startId;
			maxstartId = startId;
		}
		startId = i;
	}
	if (maxCon < maxcont) {
		maxCon = maxcont;
		maxConStart = tmpDiv[maxstartId];
	}
	else if (maxCon == maxcont)
		maxConStart = min(maxConStart,tmpDiv[maxstartId]);
	return p;
}

void Div(int x, int deep) {
	if (x <= MAXN-1 && !num[x]) { // left prime; cut out
		numDiv[deep++] = x;
		x = 1;
	}
	if (x == 1)		// ending
		Handle(deep);
	else {			// processing
		Fin(i, 2, x-1) if(!(x%i)){
			numDiv[deep] = i;
			Div(x / i, deep + 1);
		}
	}
}

int  N;
int main()
{
    //freopen("e:\\test.txt","r",stdin);
	Seive();
	while (cin >> N) {
		if (IsPrime(N)) {
			printf("1\n%d\n", N);
			continue;
		}
		maxCon = 0;
		Div(N, 1);
		printf("%d\n", maxCon);
		Fin(i, 1, maxCon)
			printf("%d%c", maxConStart + i - 1, i == maxCon ? '\n' : '*');
	}
    return 0;
}

