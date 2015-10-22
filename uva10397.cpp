
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

class unifnd {
private:
	vi p,rank;
	int _size;
public:
	void init(int N) {
		_size = N;
		rank.assign(N,0);
		p.assign(N,0);
		for(int i=0;i<N;i++) 
			p[i] = i;
	}
	int getSize() { return _size; } 
	int findSet(int x) { return (p[x] == x)?x:(p[x] = findSet(p[x]));}
	bool isSameSet(int x,int y) { return findSet(x) == findSet(y); }
	bool Union(int x,int y) {
		int xx = findSet(x); 
		int yy = findSet(y);
		if(xx == yy) return false;
		if(rank[xx] > rank[yy]) {
			p[yy] = xx;
		}
		else {
			p[xx] = yy;
			if(rank[xx] == rank[yy]) rank[yy]++;
		}
		_size--;
		return true;
	}
};

int main() {
	vector< pair<double, ii> > EdgeList;
	int tt,N,M,x,y,cx[800],cy[800]; double k;
	double dist;
	unifnd uf;
	//int qq = 0;

	while(scanf("%d",&N) == 1) {
		//if(qq > 0) printf("\n");
		for(int i=0;i<N;i++) {
			scanf("%d %d",&x,&y);
			cx[i] = x; cy[i] = y;
		}
		for(int i = 0;i<N;i++) {
			for(int j=i+1;j<N;j++) {
				dist = hypot((double)(cx[i] - cx[j]), (double)(cy[i] - cy[j]));
				EdgeList.push_back(make_pair(dist,ii(i,j)));
			}
		}

		sort(EdgeList.begin(),EdgeList.end());
		uf.init(N);
		scanf("%d",&M);
		for(int i=0;i<M;i++) {
			scanf("%d %d",&x,&y);
			uf.Union(x-1,y-1);
		}
		k = 0.0;
		for (int i=0 ; i<EdgeList.size() && uf.getSize() > 1 ; i++) {
		    pair<double, ii> front = EdgeList[i];
		    if (!uf.isSameSet(front.second.first, front.second.second)) {
		        k += front.first;
		        uf.Union(front.second.first, front.second.second);
		    }
		}
		printf("%0.2lf\n",k);
		//qq++;
		EdgeList.clear();
	}
	return 0;
}
