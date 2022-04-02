
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<int, int> P;
const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)


int main(void) {

    int a1 = 1000000000;
    ll a2 = 1000000000;

    cout << a1 * a2 << endl;


    int n, m;

    cin >> n >> m;

    vector<int> route(m);

    vector<int> a(n + 2);

    rep(i, 0, m - 1) {
        cin >> route[i];
    }
    rep(i, 0, m - 2) {
        ll min_ = min(route[i], route[i + 1]);
        ll max_ = max(route[i], route[i + 1]);

        a[min_]++;
        a[max_]--;
    }

    rep(i, 1, n) {
        a[i] += a[i - 1];
    }


    ll ret = 0;
    rep(i, 1, n - 1) {
        ll x, y, z;
        cin >> x >> y >> z;

        if (z > a[i] * (x - y)) {
            ret += a[i] * x;
        } else {
            ret += a[i] * y;
            ret += z;
        }
        // cout << ret << " " << x << " " << y << " " << z << endl;
        // cout << "ret:" << ret << endl;
    }
    cout << ret << endl;
}
