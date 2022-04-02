
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

typedef pair<ll, ll> P;

namespace mod_calc {

    ll mod_pow(ll x, ll expo, ll mod) {
        /*
            return (x  ** expor ) % mod
        */

        ll res = 1;

        while (expo > 0) {
            if (expo & 1) {
                res = (res * x) % mod;
            }
            x = (x * x) % mod;

            expo = expo >> 1;
        }
        return res;
    }

    ll mod_inv(ll x, ll mod) {

        return mod_pow(x, mod - 2, mod);
    }

    ll kaijou(ll a, ll mod) {

        ll ret = 1;
        rep(i, 1, a) {
            ret = (ret * i) % mod;
        }
        return ret;
    };

    ll kaijou_list[200001];


    ll conbination_mod(ll n, ll c, ll mod) {

        ll bunsi = kaijou_list[n];
        ll bunbo1 = kaijou_list[c];
        ll bunbo2 = kaijou_list[n - c];
        // ll bunbo2 = 2;


        // ll bunsi = kaijou(n, mod);
        // ll bunbo1 = kaijou(c, mod);
        // ll bunbo2 = kaijou(n - c, mod);
        // cout << n << " " << c << ": " << bunsi << " " << bunbo1 << " " << bunbo2 << endl;


        ll bunbo1_inv = mod_calc::mod_inv(bunbo1, mod);
        ll bunbo2_inv = mod_calc::mod_inv(bunbo2, mod);

        return (((bunsi * bunbo1_inv) % mod) * bunbo2_inv) % mod;
    }


    void init_kaijou_list(ll mod) {
        kaijou_list[0] = 1;
        kaijou_list[1] = 1;
        rep(i, 2, 200000) {
            kaijou_list[i] = (kaijou_list[i - 1] * i) % mod;
        }
    }

}  // namespace mod_calc


int main(void) {

    int n, m;
    cin >> n >> m;

    vector<ll> ruiseki(n);

    ll a;
    rep(i, 1, n - 1) {
        cin >> a;
        ruiseki[i] = ruiseki[i - 1] + a;
    }


    ll ret = 0;
    ll current_visit = 0;
    ll mod = 100000;
    rep(i, 1, m) {
        cin >> a;
        ret += (abs(ruiseki[current_visit] - ruiseki[current_visit + a])) % mod;
        // cout << ret << endl;
        current_visit = current_visit + a;
    }
    cout << (ret) % mod << endl;
}
