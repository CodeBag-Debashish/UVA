#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define r_all(x) (x).rbegin(), (x).rend()
#define inf INT_MAX
template<typename T> 
void LOG(T const& t) { 
	std::cout << t; 
}
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) {
	std::cout << first<<" "; LOG(rest ...);
}
const int K = 17;
const int N = 50010;
int P[20][N],stp,cnt;

struct suf {
	int r[2],idx;
};

bool cmp(const suf & a,const suf & b) {
	return a.r[0] == b.r[0] ? a.r[1] < b.r[1] : a.r[0] < b.r[0];
}

int LCP(int i,int j,int n) {
	int res = 0;
	if(i==j)
		return n - i;
	for(int stp = ceil(log(n)/log(2)) ; stp>=0 && i < n && j < n ; stp--)
	    if(P[stp][i] == P[stp][j]) {
				res += 1<<stp;
				i += 1<<stp;
				j += 1<<stp;
	    }
	return res;
}

int main() {
	int T;
	cin >> T;
	for(int tc=0;tc<T;tc++) {
		char A[50010];
		scanf("%s",A);
		int n = strlen(A);
		suf Sf[n+10];
		int arr[N];
		for(int i=0;i<n;i++) P[0][i] = A[i] - 'a';
		for(stp = 1,cnt = 1;(cnt >> 1)<n;stp++,cnt <<= 1) {
			for(int i=0;i<n;i++) {
				Sf[i].r[0] = P[stp-1][i];
				Sf[i].r[1] = (i+cnt)<n ? P[stp-1][i+cnt] : -1;
				Sf[i].idx = i;
			}
			sort(Sf,Sf+n,cmp);
			for(int i=0;i<n;i++) {
				P[stp][Sf[i].idx] = (i > 0) && (Sf[i].r[0] == Sf[i-1].r[0]) && (Sf[i].r[1] == Sf[i-1].r[1]) ? P[stp][Sf[i-1].idx]:i;
			}
		}
		int pos = ceil(log(n)/log(2));
		for(int i=0;i<n;i++) arr[P[pos][i]] = i;
		int sum = 0;
		for(int i=1;i < n;i++) sum += LCP(arr[i-1],arr[i],n);
		printf("%lld\n",(long long)((n*n + n) / 2) - sum);
	}
	return 0;
}
