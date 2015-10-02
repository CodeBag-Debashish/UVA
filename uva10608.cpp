#include <bits/stdc++.h>
using namespace std;
int uf[40000];
int RANK[40000];
int cnt[40000];
int ans;
int FIND(int x) {
	if( uf[x] != uf[uf[x]] ) uf[x] = FIND(uf[x]); return uf[x];
}
bool UNION(int x,int y) {
	int xx = FIND(x); int yy = FIND(y);
	if(xx == yy) return false;
	if(RANK[xx]>RANK[yy]) {
        uf[yy]=xx;
        cnt[xx]+=cnt[yy];
        if(ans < cnt[xx]) ans = cnt[xx];
	}else {
				uf[xx]=yy;
				cnt[yy]+=cnt[xx];
				if(ans < cnt[yy]) ans = cnt[yy];
				if(RANK[xx] == RANK[yy]) RANK[yy]++;
    }
}

int main() {
	int tt,size,u,v,m;
	bool blank = false;
	scanf("%d",&tt);
	for(int qq=0;qq<tt;qq++) {
		scanf("%d %d",&size,&m);
		for(int i=1;i<=size;i++) { uf[i] = i; cnt[i] = 1; RANK[i] = 0;}
		ans = 1;
		while(m--) { 
			scanf("%d %d",&u,&v);
			UNION(u,v);
		}
		cout <<ans << endl;
	}
	return 0;
}
