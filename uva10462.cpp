#include <bits/stdc++.h>
#define REP(i, j) for (int i=0 ; (j) ; i++)
 
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> ii;
 
vi pset(100);
int _size;
void initSet(int N) {REP(i, i<N) pset[i] = i; _size=N;}
int findSet(int i) {return pset[i] == i ? i : (pset[i] = findSet(pset[i]));}
int isSameSet(int i, int j) {return findSet(i) == findSet(j);}
void unionSet(int i, int j) {if (!isSameSet(i, j)) {pset[findSet(i)] = findSet(j); _size--;}}
int getSize() {return _size;}
 
int t, v, e, a, b, c;
vector<pair<int, ii> > EdgeList;
vector<int> tree;
 
int mst(int index) {
    int MST = 0; 
    initSet(v);
    REP(i, i < EdgeList.size() && getSize() > 1) {
        pair<int, ii> front = EdgeList[i];
        int a, b;
        a = front.second.first;
        b = front.second.second;
        if (i == index) continue; // ignorw the index edge
        if (!isSameSet(a, b)) {
            MST += front.first;
            unionSet(front.second.first, front.second.second);
        }
    }
    return getSize() > 1 ? 1e9 : MST;
}
 
int main() {
    scanf("%d", &t);
    REP(cas, cas<t) {
        EdgeList.clear();
        tree.clear();
        scanf("%d %d", &v, &e);
        while (e--) {
            scanf("%d %d %d", &a, &b, &c);
            a--, b--;
            EdgeList.push_back(make_pair(c, ii(a, b)));
        }
 
        initSet(v);
        sort(EdgeList.begin(), EdgeList.end());
        int MST = 0;
        REP(i, i < EdgeList.size()) {
            pair<int, ii> front = EdgeList[i];
            if (!isSameSet(front.second.first, front.second.second)) {
                MST += front.first;
                unionSet(front.second.first, front.second.second);
                tree.push_back(i);
            }
        }
        printf("Case #%d : ", cas+1);
        if (getSize() > 1) {
            printf("No way\n");
            continue;
        }
 
        int sMST = 1e9;
        REP(i, i<tree.size()) {
            sMST = min(sMST, mst(tree[i]));
        }
 
        if (sMST == 1e9) printf("No second way\n");
        else printf("%d\n", sMST);
    }
}
