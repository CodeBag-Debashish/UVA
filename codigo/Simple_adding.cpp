#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b) { return b == 0 ? a:gcd(b,a%b); }
inline int steps(int x,int y) {
	int res = 0;
	while( !( x == 1 && y == 1) ) {	
		x = x - y;
		res++;
		if(x < y) swap(x,y);
	}
	return res;
}
int main() {
	int tt,N,x,y,cnt=0;
	int minn = INT_MAX;
	cin >> tt;
	for(int i=0;i<tt;i++) {
		minn = INT_MAX;
		cin >> N;
		if(N>2) {
			if(N%2 == 0) {
				x = N/2 + 1;
				y = x - 2; 
			}else {
				x = N/2;
				y = x + 1;
			}
			if(y > x) swap(x,y);
			while(y >= 1) {
				if(gcd(x,y) == 1) {
					cnt = steps(x,y);
					minn = min(cnt,minn);
				}
				x++; y--;
			}
			cout << minn+1 << endl;
		}else {
			if(N==1) cout << 0 << endl;
			else cout << 1 << endl;
		}
	}

	return 0;

}
