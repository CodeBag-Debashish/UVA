#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
inline bool check(ULL n) {
	vector<int> a;
	while(n > 0) {
		a.push_back(n%10);
		n = n/10;
	}
	int l = a.size();
	for(int i=l-1;i>=1;i--) {
		if(a[i] > a[i-1])
			return false;
	}
	return true;	
}
int main() {
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++) {
		cout <<"Case #"<<q<<": ";
		ULL num,i;
		cin >> num;
		for(i = num;i>=0;i--) {
			if(check(i))
				break;
		}
		cout << i << endl;
	}
	return 0;
}
