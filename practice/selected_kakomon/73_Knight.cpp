
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

    ll kaijou(ll a, ll mod) {

        ll ret = 1;
        rep(i, 1, a) {
            ret = (ret * i) % mod;
        }
        return ret;
    };

    ll conbination_mod(ll n, ll c, ll mod) {

        ll bunsi = kaijou(n, mod);
        ll bunbo1 = kaijou(c, mod);
        ll bunbo2 = kaijou(n - c, mod);


        ll bunbo1_inv = mod_calc::mod_inv(bunbo1, mod);
        ll bunbo2_inv = mod_calc::mod_inv(bunbo2, mod);

        return (((bunsi * bunbo1_inv) % mod) * bunbo2_inv) % mod;
    }

}  // namespace mod_calc

int main(void) {

    ll X, Y;
    ll mod = 1e9 + 7;

    cin >> X >> Y;

    ll b = X + Y;

    if (b % 3 != 0) {
        cout << "0";
        return 0;
    }


    ll counter = 0;
    ll x = b / 3, y = b - x;


    while ((y - counter) >= b / 3) {
        if ((x + counter == X) && (y - counter == Y)) {
            break;
        }
        counter++;
    }

    if ((y - counter) < b / 3) {
        cout << "0";
        return 0;
    }
    // cout << b / 3 << " " << counter << endl;
    cout << mod_calc::conbination_mod(b / 3, counter, mod) << endl;
}
