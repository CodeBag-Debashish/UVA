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


#define int_inf INT_MAX
#define long_inf LLONG_MAX

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

long long solve(std::vector<int> & a,int start,int end) {
	int n = a.size();
	long long cnt = 0;
	std::vector<long long> f(n+1,0);
	for(int i=1;i<n+1;i++) {
		f[i] = f[i-1] + a[i-1];
	}
	sort(all(f));
	int lo,hi;
	for(int i=0;i<n+1;i++) {
		lo = lower_bound(f.begin(),f.begin()+i,f[i]-end) - f.begin();
		hi = upper_bound(f.begin(),f.begin()+i,f[i]-start) - f.begin();
		cnt += hi - lo;
	}
	return cnt;
}

int main() {
	int T,N,P,x;
	std::vector<int> v;
	cin >> T;
	for(int tc=0;tc<T;tc++) {
		scanf("%d %d",&N,&P);
		for(int i=0;i<N;i++) {
			scanf("%d",&x);
			v.pb(x);
		}
		/*cout << solve(v,0,P) << endl;*/
		printf("Case #%d: %lld\n",tc+1,solve(v,0,P));
		v.clear();
	}
	
	return 0;
}
