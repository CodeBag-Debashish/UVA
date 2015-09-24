#include <bits/stdc++.h>
using namespace std;


//int initSet(int _size) {
//	uf = new int[_size];
//	rank = new int[_size];
//	memset(rank,0,sizeof(int)*_size);
//	for(int i=0;i<_size;i++) {uf[i] = i;}
//}

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
	char tag;
	int tt,size,u,v,yes,no;
	bool blank = false;
	scanf("%d",&tt);
	for(int qq=0;qq<tt;qq++) {
		yes = no = 0;
		scanf("%d",&size); getchar();
		int * uf = new int[size+1];
		int * rank = new int[size+1];
		memset(rank,0,sizeof(int)*(size+1));
		for(int i=1;i<=size;i++) {uf[i] = i;}
		while((tag = getchar ()) && isalpha (tag) ) {
			scanf("%d%d",&u,&v); getchar();
			if(tag == 'c') {
				UNION(u,v,uf,rank);
			} else {
				if(FIND(u,uf) == FIND(v,uf))
					yes++;
				else no++;
			}
		}
		if(blank) printf("\n"); blank = true;
		cout << yes<<","<<no<<endl;
		delete[] uf;
		delete[] rank;
	}
	return 0;
}
