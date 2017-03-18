#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
#define N 35
ULL fibo[N];
int main() {
	int n;
	fibo[0] = 1;
	fibo[1] = 2;
	fibo[2] = 4;
	for(int i=3;i<N;i++) {
		fibo[i] = fibo[i-1] + fibo[i-2] + fibo[i-3];
	}	
	while(scanf("%d",&n)) {
		if(n == 0) break;
		cout << ((1<<n) - fibo[n]) << endl; 
	}
}
