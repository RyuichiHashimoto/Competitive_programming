
#include <bits/stdc++.h>

#include <cmath>
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

int main(void) {

    int n, k;
    cin >> n >> k;

    vector<ll> before(k);
    vector<ll> after(n - k);
    map<ll, ll> pos;


    rep(i, 0, k - 1) {
        cin >> before[i];
    }
    rep(i, k, n - 1) {
        cin >> after[i - k];
        ll val = after[i - k];
        if (pos[val] == 0) {
            pos[val] = i - k + 1;
        }
    }

    reverse(before.begin(), before.end());
    sort(after.begin(), after.end());


    ll short_path = 0x7FFFFFF;

    for (int i = n - k - 1; i >= 0; i--) {
        if (i == n - k - 1) {
            short_path = pos[after[i]];
        } else {
            short_path = min(pos[after[i]], short_path);
            pos[after[i]] = short_path;
        }
        // cout << i << " " << after[i] << " " << pos[after[i]] << endl;
    }


    ll INF = 0x7FFFFFFFFF;
    ll ans = INF;
    rep(i, 0, k - 1) {
        auto s = lower_bound(after.begin(), after.end(), before[i] + 1);
        if (s != after.end()) {
            ll val = *s;
            ans = min(ans, pos[val] + i);
        }
    }
    if (ans == INF) {
        cout << "-1";
    } else {
        cout << ans << endl;
    }


    return 0;
}