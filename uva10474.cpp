#include <bits/stdc++.h>
using namespace std;
int main() {
	int N,Q,x,q=1;
	std::vector<int> a;
	while(scanf("%d%d",&N,&Q) == 2,(N||Q)) {
		for(int i=0;i<N;i++) {
			cin >> x; a.push_back(x);
		}
		sort(a.begin(),a.end());
		cout <<"CASE# "<<q++<<":"<<endl;
		for(int i=0;i<Q;i++) {
			cin >> x;
			auto pos = lower_bound(a.begin(),a.end(),x);
			if (pos != a.end() && *pos == x) {
				cout <<x<<" found at "<<pos - a.begin() + 1<<endl;
			}else {
				cout << x <<" not found"<<endl;
			}
		}
		a.clear();
	}
}
