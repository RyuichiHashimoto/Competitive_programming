
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<int, int> P;
const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<ll, ll> P;
class Union_Find {
  private:
    int *par;
    int *rank;

  public:
    Union_Find(int size) {
        par = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    ~Union_Find() {
        delete par;
        delete rank;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            par[x] = root(par[x]);
            return par[x];
        }
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);

        if (x == y) return;

        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};


int main(void) {

    int n, q;

    cin >> n >> q;

    Union_Find tree(n + 1);

    int a, b, c;
    rep(i, 1, q) {

        cin >> a >> b >> c;
        // cout << a << " " << i << endl;

        if (a == 0) {
            tree.unite(b, c);
        } else if (a == 1) {
            if (tree.same(b, c)) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        }
    }
}
