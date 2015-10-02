#include <bits/stdc++.h>
using namespace std;
int Find(int x,std::vector<int> & uf) {
	if(uf[x] != uf[uf[x]]) uf[x] = Find(uf[x],uf); return uf[x];
}
bool Union(int x,int y,std::vector<int> &uf,std::vector<int> &rank) {
	int xx = Find(x,uf) ; int yy = Find(y,uf);
	if( xx == yy) { return false;}
	if(rank[xx] > rank[yy]) swap(xx,yy);
	if(rank[xx] == rank[yy]) rank[yy]++;
	uf[xx] = yy;
	return true;
}
int main() {
	int n,m,u,v;
	int qq = 0;
	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;
		qq++;
		std::vector<int> uf,rank;
		uf.resize(n); rank.resize(n);
		for(int i=0;i<n;i++) {uf[i] = i; rank[i] = 0;}
		for(int i=0;i<m;i++) {
			cin >> u>>v;
			Union(u-1,v-1,uf,rank);
		}
		sort(uf.begin(),uf.end());
		int count = 1;
		for(int i=1;i<n;i++) {
			if(uf[i] != uf[i-1]) count++;
		}
		if(qq>1) cout << endl;
		cout <<"Case "<<qq<<": "<<count;
		uf.clear(); rank.clear();
	}
	return 0;
}
