
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

        bool is_prime = true;
        for (ll i = 2; i * i <= mod; i++) {
            if (mod % i == 0) is_prime = false;
        }
        is_prime = (is_prime) && (mod != 1);

        if (!is_prime) {
            cerr << "mod must be prime number";
            exit(-1);
        }

        return mod_pow(x, mod - 2, mod);
    }

    ll conbination_mod(ll n, ll c, ll mod) {
        ll bunsi = kaijou(n, mod);
        ll bunbo1 = kaijou(c, mod);
        ll bunbo2 = kaijou(n - c, mod);

        ll bunbo1_inv = mod_calc::mod_inv(bunbo1, mod);
        ll bunbo2_inv = mod_calc::mod_inv(bunbo2, mod);

        return (((bunsi * bunbo1_inv) % mod) * bunbo2_inv) % mod;
    }

}  // namespace mod_calc

ll kaijou(ll a, ll mod) {

    if (a == 1) {
        return 1;
    } else {
        return (a * kaijou(a - 1, mod)) % mod;
    }
};


int main(void) {

    ll W, H;

    cin >> W >> H;

    ll mod = 1000000007;

    W--;
    H--;

    ll a = kaijou(W + H, mod);

    if (min(W, H) == 1) {
        cout << a << endl;
        return 0;
    }
    ll b_w = kaijou(W, mod);
    ll b_h = kaijou(H, mod);
    // cout << a << " " << b_w << " " << b_h << endl;

    ll b_w_inv = mod_calc::mod_inv(b_w, mod);
    ll b_h_inv = mod_calc::mod_inv(b_h, mod);


    cout << conbination_mod(W + H, W, mod) << endl;
    // cout << (((a * b_w_inv) % mod) * b_h_inv) % mod << endl;
}
