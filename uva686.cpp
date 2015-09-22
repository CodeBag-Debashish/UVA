#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000005
int main() {
    bool * prime = new bool[SIZE],ok= true,done = false;
    memset(prime,true,sizeof(bool)*SIZE);
    prime[1] = prime[0] = false;
    for(int i=2;i*i<=SIZE;i++) {
        if(prime[i])
            for(int j=2;i*j<=SIZE;j++) {
                prime[i*j] = false;
            }
    }
    int *s =new int[2];
    int n,cnt;
    while(cin >> n) {
        cnt = 0;
        if(n == 0) break;
        done = false;
        for(int i=2;(i <= n/2) && (!done);i++) {
            if(prime[i] && prime[n-i]) {
                cnt++;
            }
        }
        cout << cnt <<endl;
    }
    delete[] prime;
    delete[] s;
    return 0;    
}
