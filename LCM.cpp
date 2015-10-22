#include <bits/stdc++.h>
using namespace std;
const int MOD = 1;
#define MAX_NUM 10000000
vector<int> firstPrime(MAX_NUM+1, -1);   	// A modified Erathostenes Sieve, firstPrime[i] will have the largest prime factor of i, 
																					// so when firstPrime[i] == i, i is prime.
vector<int> primeAppears(MAX_NUM+1, 0);					// primeAppears[i] the exponent of prime i in the results's prime factorization

void m_sieve() {
  for (int i = 2; i <= MAX_NUM; i++) {
		if (firstPrime[i] == -1) 
			for (int j = i; j <= MAX_NUM; j += i) firstPrime[j] = i;
	}
}

int LCM(vector<int> & a) {
  m_sieve();
  set<int> primes_facs;
  for (const auto & elem: a) {
      int x = elem;
      while (x != 1) {
				int y = firstPrime[x];
				primes_facs.insert(y);
				int r = 0;
				while (x % y == 0) {
					r++;
					x /= y;
				}
				primeAppears[y] = std::max(primeAppears[y], r);
      }
  }
  long r = 1;
  for (const auto & elem: primes_facs) {
      if (firstPrime[elem] == elem)
      	cout << elem <<" is prime " << endl;
          for (int j = 0; j < primeAppears[elem]; j++) r = (r * elem) ; // r = (r * elem)%MOD id needed
  }
  return int(r);
}
int main() {
	std::vector<int> v = {100,112,140};
	cout << LCM(v) << endl;
	return 0;
}
