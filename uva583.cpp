#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,x;
	bool neg,first ;
	while(cin >> x) {
		if( x == 0) break; n = x;
		neg = false; first = true;
		cout <<x<<" = ";
		if(n < 0) { n = -n; x = -x;; neg = true; }
		if(neg) cout << "-1 x ";
		while(n%2 == 0) {
			if(first)  {cout <<2; first = false; n = n / 2; }
			else {cout <<" x "<<2; n = n / 2;}
		}
		for(int i=3;i<=sqrt(n);i+=2) {
			while(n%i == 0) {
				if(first) { cout <<i; first = false; n = n/i; }
				else {
					cout <<" x "<<i; n = n/i;
				}
			}
		}
		if(n > 2 && n == x) cout << n;
		if(n > 2 && n != x) cout <<" x "<<n;
		cout << endl;
	}
}
