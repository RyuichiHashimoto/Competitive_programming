#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;

int ctoi(char a) {
    return a - '0';
}

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;
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

ll func(ll val, ll keta, ll mod, ll idx) {
    ll ret = mod_calc::mod_pow(10, keta - 1, mod);

    if (keta == 1) {
        return (ret * val) % mod;
    }

    ll bef = 5 * mod_calc::mod_pow(10, keta - 3, mod);
    ll aft = mod_calc::mod_pow(2, keta - 3, mod);

    bef -= aft;
    if (bef < 0) {
        bef += mod;
    }
    // cout <<  << endl;
    ll last = (bef * mod_calc::mod_inv(4, mod)) % mod;

    ll modifi = mod_calc::mod_pow(10, keta - 1, mod) * (mod_calc::mod_inv(mod_calc::mod_pow(2, keta - 1, mod), mod));
    modifi %= mod;
    last += modifi;
    last %= mod;

    return (((ret + last) % mod) * val) % mod;
    // return ret;
}


int main() {

    string s;
    cin >> s;

    ll ret = 0;
    ll mod = 998244353;

    // cout << func(1, 4, mod);
    for (int i = 0; i < s.size(); i++) {
        ll keta = s.size() - i;
        ret += func(s[i] - '0', keta, mod, i);
        ret %= mod;
        cout << func(s[i] - '0', keta, mod, i) << endl;
    }
    cout << ret << endl;
    return 0;
}