#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
bool is_ok(std::vector<int> &a) {
	for(int i=a.size()-1;i>=1;i--) {
		if(a[i] > a[i-1]) return false;
	}
	return true;
}
inline int check(ULL n,vector<int> &a) {
	while(n > 0) {
		a.push_back(n%10);
		n = n/10;
	}
	int l = a.size();
	bool ok = true;
	while(!is_ok(a)) {
		ok = true;
		int i = l-1;
		while(ok && i >=1 ) {
			(a[i]<=a[i-1])?i--:ok = false;
		}
		if(i>0) {
			a[i]--;
			for(int j = i-1;j>=0;j--) {
				a[j] = 9;
			}
		}
	}
	int k;
	for(k=l-1;k>=0;k--) {
		if(a[k] != 0) break;
	}
	return k;
}
int main() {
	int T;
	vector<int> a;
	scanf("%d",&T);
	for(int q=1;q<=T;q++) {
		cout <<"Case #"<<q<<": ";
		ULL num,i;
		cin >> num;
		int pos = check(num,a);
		for(int i = pos;i>=0;i--) {
			cout << a[i];
		}
		cout << endl;
		a.clear();
	}
	return 0;
}
