#include <bits/stdc++.h>
using namespace std;
unsigned int mask;
const int M = 2;
const int N = 5;
int no_of_sol = 0;
int all_placed = (1<<N)-1;
int pos[N];
void backtrack(int col_mask,int rwm,int col) {
	if(col == M) {
		no_of_sol++;
		for(int r = 0;r<N;r++) {
			for(int c = 0;c<N;c++) {
				(pos[c] == r && mask&(1<<c))?printf("#  "):printf(".  ");
			}
			printf("\n\n");
		}
		printf("-------------\n\n");
		return;	
	}else {
		if(col_mask) {
			int col_pos = __builtin_ctz(col_mask);
			int mask = all_placed & (~(rwm)); // mask tells us which positions 
			// are free now to place rooks to place in this col
			while(mask) {
				int m = mask & -mask;
				mask = mask - m;
				pos[col_pos] = __builtin_ctz(m); 	// pos[] is an helper array
				// to display results
				col_mask = col_mask & (~(1<<col_pos));
				backtrack(col_mask,rwm|m,col+1);
			}
		}
	}
}
// solve() creates the k column subsets out N columns
// when a subset is ready ( or the mask is ready )
// we call backtrack() to choose the rows to place 
void solve(int n,int k,int idx,int cnt) {
	if(cnt == (n-k)) {
		// column subset mask is ready
		// or we have selected k column
		// now row selection will be controlled by row_mask
		// and the exact positions will be handled in the backtrack() function
		backtrack(mask,0,0);
		/*backtrack(column_subset,row_mask,no_of_rooks_placed);*/
		return;
	}else if(idx >= 0) {
		// subset mask creating
		for(int i=idx;i>=0;i--) {
			mask &= ~(1<<i);
			solve(n,k,i - 1,cnt+1);
			mask |= (1<<i);
		}
	}
}
int main() {
	int n = N,k = M;
	for(int i=0;i<n;i++) mask |= (1<<i);
	solve(n,k,n-1,0);
	printf("%d\n",no_of_sol);
}
