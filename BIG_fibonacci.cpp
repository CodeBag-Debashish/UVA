/*

The question is simple and straight forward !!!

You are given a recurrence relation for a series of number defined by

G(n)= G(n-1) + 3*G(n-2) + 3*G(n-3) + G(n-4)

where the initial seeds are

G(1)=1

G(2)=3

G(3)=3

G(4)=1

You will be given n , You have to find the value of G(n)

Input Format

First line contains an integer 't' denoting the number testcases

Next t lines contains an integer 'n'

Output Format

For given n print the value of G(n) in a new line

As G(n) can be large print G(n) modulus 10000007

Contraints

1 ≤ t ≤ 10000

1 ≤ n ≤ 10^18


*/


#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 10000007;
const int K = 4;

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = ( C[i][j] + A[i][k] * B[k][j] ) % MOD;
    return C;
}

// computes A ^ p
matrix pow(matrix A, ll p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

// returns the N-th term of Fibonacci sequence
int fib(ll N)
{
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = 1;
    F1[2] = 3;
    F1[3] = 3;
    F1[4] = 1;



    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1,T[1][3] = 0,T[1][4] = 0;
    T[2][1] = 0, T[2][2] = 0,T[2][3] = 1,T[2][4] = 0;
    T[3][1] = 0, T[3][2] = 0,T[3][3] = 0,T[3][4] = 1;
    T[4][1] = 1, T[4][2] = 3,T[4][3] = 3,T[4][4] = 1;

    // raise T to the (N-1)th power
    if (N == 1)
        return 1;
    T = pow(T, N-1);

    // the answer is the first row of T . F1
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}
int main()
{
    ll t;
    ll n;
    cin >> t;
    for(int i=0;i<t;i++)
    {
            cin >> n;
            cout << fib(n)%MOD<<endl;    
    }

    return 0;
}
