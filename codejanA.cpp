#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	string a;int k;
	for(int q=1;q<=T;q++) {
		int cnt = 0;
		cout <<"Case #"<<q<<": ";
		cin>>a>>k;
		int i=0;
		bool done = true;
		while(i < a.length()) {
			if(a[i] == '+') {
				i++;
				continue;
			}else {
				if((i+k-1) < a.length()) {
					int m = 0;
					while(m < k) {
						(a[i+m] == '+')?a[i+m] = '-':a[i+m] = '+';
						m++;
					}
					cnt++;
					i++;
				}else {
					done = false;
					break;
				}

			}

		}
		if(!done) cout << "IMPOSSIBLE"<<endl;
		else cout << cnt << endl;
	}
}
