#include <bits/stdc++.h>
using namespace std;
int main() {
	int T,position,depth,balls;
	cin >> T;
	for(int qq=0;qq<T;qq++) {
		cin >> depth >> balls;
		position = 1;
		for(int level=1;level<depth;level++) {
			position = balls&1?position<<1:position<<1|1;
			balls = (balls + 1) >> 1;
		}
		cout << position << endl;
	}
	return 0;	
}
