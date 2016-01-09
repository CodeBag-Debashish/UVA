#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define r_all(x) (x).rbegin(), (x).rend()
#define FORD(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); --i)
#define FORI(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

template<typename T> 
void printelem(T & container) {for(auto & elem: container) cout << elem << endl; }
template<typename T> 
void LOG(T const& t) { std::cout << t; }
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) { std::cout << first<<" "; LOG(rest ...);}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

int T,N,x,y;
#define EPS 1e-9
double data[2000][2000];

long long countPairsWithDiff0(double a[], int n) {
	long long cnt = 0;
	long long p_res = 0;
	sort(a, a+n);
	int r;
	for(int i=1;i<n;i++) {
		r = i;
		cnt = 0;
		while(r < n) {
			if(fabs(a[i] - a[r]) <= EPS ) {
				if(i != r) cnt++;
			}else break;
			r++;
		}
		p_res += cnt;
	}
	return p_res;
}

int main() {
	long long n;
	vector<pair<int,int>> pts;
	cin >> T;
	for(int tc=0;tc<T;tc++) {
		n=0; pts.clear();
		scanf("%d",&N);
		for(int i=0;i<N;i++) {
			scanf("%d %d",&x,&y);
			pts.pb(mp(x,y));
		}
		for(int pt=0;pt<pts.size();pt++) {
			for(int p_pt=0;p_pt<pts.size();p_pt++) {
				if(pt==p_pt) {
					data[pt][p_pt] = -INT_MAX;
					continue;
				}
				data[pt][p_pt] = hypot(pts[pt].ff-pts[p_pt].ff,pts[pt].ss-pts[p_pt].ss);
			}
			/*LOG("test case ",tc+1,"point = ",pt+1," ans = ",countPairsWithDiff0(data[pt],N),"\n");*/
			n += countPairsWithDiff0(data[pt],N);
		}
		printf("Case #%d: %lld\n",tc+1,n);
	}
	return 0;
}
