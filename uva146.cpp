#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	while(cin >> s) {
		if(s[0] == '#') break;
		(next_permutation(s.begin(),s.end()))?cout << s << endl:cout<<"No Successor"<<endl;
	}
	return 0;
}
