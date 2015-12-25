#include <bits/stdc++.h>
#define N 100000
long long nodes[4*N+2],buffer[4*N+2];

long long query(int x, int y, int l, int r, int id);

void update(int x, int y, int l, int r, int id, long long val) {
    if (r < x || y < l) return;


    // process buffer first and clear it 
    if (buffer[id] != 0) {
        if (l == r) {
            nodes[id] += buffer[id];
        } else {
            nodes[id] += buffer[id]*(r - l + 1); // id is covering (r-l+1) no of elements
            buffer[id * 2 + 1] += buffer[id];
            buffer[id * 2 + 2] += buffer[id];
        }
        buffer[id] = 0;
    }

    // now increment with new val ... only to nodes[id] not the whole tree
    if (x <= l && r <= y) {
        if (l == r) {
            nodes[id] += val;
        } else {
            nodes[id] += val * (r - l + 1);  // id is covering (r-l+1) no of elements
            buffer[id * 2 + 1] += val;
            buffer[id * 2 + 2] += val;
        }
        return;
    }

    int mid = (l + r) / 2;
    update(x, y, l, mid, id * 2 + 1, val);
    update(x, y, mid + 1, r, id * 2 + 2, val);


/*    int left = id * 2 + 1;
    int right = left + 1;*/


    nodes[id] = query(l, mid, l, mid, id * 2 + 1) + query(mid + 1, r, mid + 1, r, id * 2 + 2);
}

long long query(int x, int y, int l, int r, int id) {
    if (r < x || y < l)return 0;


    // process buffer first and clear it 
    if (buffer[id] != 0) {
        if (l == r) {
            nodes[id] += buffer[id];
        } else {
            nodes[id] += buffer[id]*(r - l + 1);
            buffer[id * 2 + 1] += buffer[id];
            buffer[id * 2 + 2] += buffer[id];
        }
        buffer[id] = 0;
    }
    if (x <= l && r <= y) return nodes[id];

    int mid = (l + r) / 2;
    long long left = query(x, y, l, mid, id * 2 + 1);
    long long right = query(x, y, mid + 1, r, id * 2 + 2);
    return left + right;
}



int main() {
    int nCases;
    scanf("%d", &nCases);
    while (nCases--) {
        int n, C;
        scanf("%d %d", &n, &C);
        for(int i=0;i<(4*N+2);i++) {
            nodes[i] = 0;
            buffer[i] = 0;
        }
        for (int i = 0; i < C; ++i) {
            int type, p, q;
            long long v;
            scanf("%d", &type);
            if (type == 0) {
                scanf("%d %d %lld", &p, &q, &v);
                update(p - 1, q - 1, 0, n - 1, 0, v);
            } else {
                scanf("%d %d", &p, &q);
                printf("%lld\n", query(p - 1, q - 1, 0, n - 1, 0));
            }
        }

    }
}
