#include <bits/stdc++.h>

#include <cassert>
#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<ll, ll> P;
const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)


int main(void) {

    int n;
    cin >> n;

    vector<vector<ll>> ret(n + 1, vector<ll>(n + 1, 0x7FFFFFFFFFFFFF));
    vector<vector<ll>> init(n + 1, vector<ll>(n + 1, 0x7FFFFFFFFFFFFF));

    priority_queue<P, vector<P>, greater<P>> pque;
    // priority_queue<P> pque;

    rep(i, 1, n) {
        rep(j, 1, n) {
            cin >> ret[i][j];
            if (i < j) {
                pque.push(P{ret[i][j], i + 1000 * j});
            }
        }
    }


    ll ans = 0;
    while (!pque.empty()) {
        P p = pque.top();
        pque.pop();
        // cout << p.first << endl;
        // cout << pque.top().first << " " << pque.top().second;

        ll from = p.second % 1000;
        ll to = p.second / 1000;


        //経由した中で最小のもの。
        ll min_distance = 0x7FFFFFFFFFFFFFF;

        rep(k, 1, n) {
            if (from == k or to == k) {
                continue;
            }

            min_distance = min(min_distance, ret[to][k] + ret[k][from]);
        }


        // 経由がない場合
        if (min_distance > p.first) {

            init[from][to] = p.first;
            init[to][from] = p.first;
            ans += p.first;
        } else if (min_distance < p.first) {
            cout << "-1";
            return 0;
        } else if (min_distance == p.first) {
        }
    }
    cout << ans << endl;
}