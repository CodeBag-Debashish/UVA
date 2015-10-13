#include <bits/stdc++.h>
using namespace std;

int FIND(int x,int * uf) {
	if( uf[x] != uf[uf[x]] ) uf[x] = FIND(uf[x],uf); return uf[x];
}
bool UNION(int x,int y,int * uf,int * rank) {
	int xx = FIND(x,uf); int yy = FIND(y,uf);
	if(xx == yy) return false;
	if(rank[xx] > rank[yy]) {int t=xx; xx = yy; yy = t;}
	if(rank[xx] == rank[yy]) rank[yy]++;
	uf[xx] = yy;
	return true;
}
int main() {
	int tt,n,m,u,v,w;
	vector<pair<pair<int,int>,int>> edge;
	vector<pair<pair<int,int>,int>> mst;
	cin >> tt;
	for(int qq=0;qq<tt;qq++) {
		cin >> n>>m;
		for(int i=0;i<m;i++) {
			cin >>u>>v>>w;
			edge.push_back(make_pair(make_pair(u,v),w));
		}
		sort(edge.begin(),edge.end(),[](const std::pair<pair<int,int>,int> &left, const std::pair<pair<int,int>,int> &right) { 
			return left.second < right.second;
		});
		int * uf = new int[n+1];
		int * rank = new int[n+1];
		//mst.resize(n+1);
		memset(rank,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;i++) {uf[i] = i;}
		int trees = n,f_sum = 0,s_sum = 0,min_s_sum = INT_MAX;
		for(int i=0;i<m && trees >1;i++) {
			if(UNION(edge[i].first.first,edge[i].first.second,uf,rank)) {
				mst.push_back(edge[i]);
				trees--;
				f_sum += edge[i].second;
			}
		}

		//memset(rank,0,sizeof(int)*(n+1));
		//for(int i=1;i<=n;i++) {uf[i] = i; rank[i] = 0;}
		
		trees = n; s_sum = 0; min_s_sum = INT_MAX;
		int cnt = 0;
		for(int i=0;i<mst.size();i++) {
			
			cnt = 0;
			int a = mst[i].first.first;
			int b = mst[i].first.second;
			for(int i=1;i<=n;i++) {uf[i] = i; rank[i] = 0;}
			s_sum = 0; trees = n;
			
			for(int j=0;j<m && trees > 1;j++) { 																		// loop through the whole edge list except mst[i] th edge
				if( !((a == edge[j].first.first) && (b == edge[j].first.second)) ) {	// block mst[i] th edge
					if(UNION(edge[j].first.first,edge[j].first.second,uf,rank)) {
						cnt++;
						trees--;
						s_sum += edge[j].second;
					}	
				}
			}
			if(cnt == n-1 && min_s_sum > s_sum) {
				min_s_sum = s_sum;
			}
		}
		
		//for(int i=0;i<mst.size();i++) {
		//	cout << mst[i].first.first <<" "<<mst[i].first.second<<endl;
		//}
		
		cout << f_sum<<" "<< min_s_sum <<endl;
		delete[] rank;
		delete[] uf;
		edge.clear();
		mst.clear();
	}
	return 0;
}
