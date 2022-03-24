
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<ll, ll> P;
const ll MAX_N = 1.0E5;
// const ll ll_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

typedef pair<ll, ll> P;
class Union_Find {
  private:
    ll *par;
    ll *rank;
    ll sz;
    ll routes;
    ll huben;
    map<ll, ll> exist;

  public:
    Union_Find(ll size) {
        par = new ll[size];
        rank = new ll[size];
        sz = size;

        routes = 0;


        huben = (size - 1) * (size - 2) / 2;

        for (ll i = 0; i < size; i++) {
            par[i] = i;
            rank[i] = 0;
            exist[i] = 1;
        }
    }

    ~Union_Find() {
        delete par;
        delete rank;
    }

    ll root(ll x) {
        if (par[x] == x) {
            return x;
        } else {
            par[x] = root(par[x]);
            return par[x];
        }
    }

    ll unite(ll x, ll y) {
        x = root(x);
        y = root(y);

        if (x == y) return huben - routes;

        if (rank[x] < rank[y]) {
            par[x] = y;
            routes -= exist[y] * (exist[y] - 1) / 2;
            routes -= exist[x] * (exist[x] - 1) / 2;

            exist[y] += exist[x];
            exist[x] = 0;
            routes += exist[y] * (exist[y] - 1) / 2;


        } else {
            par[y] = x;

            if (rank[x] == rank[y]) {
                rank[x]++;
            }

            routes -= exist[y] * (exist[y] - 1) / 2;
            routes -= exist[x] * (exist[x] - 1) / 2;

            exist[x] += exist[y];
            exist[y] = 0;
            routes += exist[x] * (exist[x] - 1) / 2;
        }
        return huben - routes;
    }

    bool same(ll x, ll y) {
        return root(x) == root(y);
    }
};


int main(void) {


    ll N, M;

    cin >> N >> M;


    vector<P> bridges(M);
    rep(i, 1, M) {
        cin >> bridges[i - 1].first >> bridges[i - 1].second;
    }

    reverse(bridges.begin(), bridges.end());

    Union_Find tree(N + 1);


    vector<ll> s(M);
    rep(i, 0, M - 2) {
        s[i + 1] = tree.unite(bridges[i].first, bridges[i].second);
    }
    s[0] = N * (N - 1) / 2;
    reverse(s.begin(), s.end());
    rep(i, 0, M - 1) {
        cout << s[i] << endl;
    }
}
