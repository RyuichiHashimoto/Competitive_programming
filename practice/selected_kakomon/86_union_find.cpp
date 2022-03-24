
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

    int n, m;

    cin >> n >> m;


    vector<P> vec(m + 1);

    rep(i, 1, m) {
        cin >> vec[i].first >> vec[i].second;
    }

    int ret = 0;
    rep(i, 1, m) {
        Union_Find tree(n + 1);
        rep(j, 1, m) {
            if (j == i) {
                continue;
            }
            tree.unite(vec[j].first, vec[j].second);
        }

        bool ok = true;
        rep(a, 1, n) {
            rep(b, 1, n) {
                if (!tree.same(a, b)) {
                    ok = false;
                }
            }
        }
        if (!ok) {
            ret++;
        }
    }

    cout << ret << endl;
}
