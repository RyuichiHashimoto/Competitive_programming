
#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#include <numeric>
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


namespace gcd_lcd {

    template <typename T>
    T gcd(T x, T y) {
        if (x < y) swap(x, y);
        // xの方が常に大きい
        T r;
        while (y > 0) {
            r = x % y;
            x = y;
            y = r;
        }
        return x;
    }

    template <typename T>
    T lcm(T x, T y) {
        return T(x / gcd(x, y)) * y;
    }

    template <typename T>
    T gcd(vector<T> &array) {
        T ret = array[0];
        for (T a : array) {
            ret = gcd(ret, a);
        }
        return ret;
    }

    template <typename T>
    T lcm(vector<T> &array) {
        T ret = array[0];
        for (T a : array) {
            ret = lcm(ret, a);
        }
        return ret;
    }

};  // namespace gcd_lcd


int main(void) {

    ll N, M;

    cin >> N >> M;
    M = M << 1;
    vector<ll> Array(N);
    rep(i, 1, N) {
        cin >> Array[i - 1];
    }
    ll val = gcd_lcd::lcm(Array);

    vector<ll> nokori(N);

    int even = 0, odd = 0;
    rep(i, 1, N) {
        nokori[i - 1] = val / Array[i - 1];

        if (nokori[i - 1] & 1) {
            odd++;
        } else {
            even++;
        }
    }

    if (even == 0) {
        if (M / val & 1) {
            cout << (M / val) / 2 + 1 << endl;
        } else {

            cout << (M / val) / 2 << endl;
        }
    } else if (odd == 0) {
        return 1;
    } else {
        cout << 0 << endl;
    }
}
