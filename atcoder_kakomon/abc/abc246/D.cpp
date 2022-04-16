#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<int, int> P;


ll calc(ll x, ll y) {
    return (x + y) * (x * x + y * y);
}


int main(void) {

    ll N;

    cin >> N;

    ll x = (1E6), y = (1E6);

    ll l = 0;
    ll r = 1E6;
    ll ret_min = 0x7FFFFFFFFFFFFFFF;

    rep(i, 0, 1E6) {
        ll l = -1;
        ll r = 1E6 + 10;
        while (r - l > 1) {

            ll mid = (r + l) / 2;

            ll ret = calc(mid, i);
            if (ret < N) {
                l = mid;
            } else {
                r = mid;
            }
        }
        x = r;
        if (calc(x, i) >= N) {
            // cout << calc(x, i) << endl;
            ret_min = min(ret_min, calc(x, i));
        }
    }
    cout << ret_min << endl;
}
