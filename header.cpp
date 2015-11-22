#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fe first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define r_all(x) (x).rbegin(), (x).rend()
#define FORD(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); --i)
#define FORI(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

template<typename T> void printelem(T & container) {for(auto & elem: container) cout << elem << endl; }
template<typename T> void LOG(T const& t) { std::cout << t<<" "; }
template<typename First, typename ... Rest> void LOG(First const& first, Rest const& ... rest) { std::cout << first<<" "; LOG(rest ...);}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
