#include <bits/stdc++.h>
using namespace std;
int main() {
	int tt,n,count;
	bool swapped;
	cin >> tt;
	for(int qq=0;qq<tt;qq++) {
		cin >> n;
		int * x = new int[n];
		for(int i=0;i<n;i++) {
			scanf("%d",x+i);
		}
		count = 0;
		swapped = true;
		while(swapped) {
			swapped = false;
			for(int i=0;i<n-1;i++) {
				if(x[i] > x[i+1]) {
					swap(x[i],x[i+1]);
					count++;
					swapped = true;
				}
			}
		}
		cout <<"Optimal train swapping takes "<<count<<" swaps."<<endl;
		delete[] x;
	}
	return 0;
}
