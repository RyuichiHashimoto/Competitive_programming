#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <limits.h>

#include <queue>

typedef long long ll;

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


ll pow(ll x, ll n) {


    ll ret = 1;
    while (n > 0) {
        if (n & 1 == 1) {
            ret = (ret * x);
        }
        x = (x * x);

        n = n >> 1;
    }
    return ret;
}


namespace prime_number {

    typedef long long ll;
    typedef pair<long, long> P;
    const int MAX_N = 400000;

    bool is_prime(ll number) {
        /*
            numberが素数か判定する。


            True: 引数 numberが素数
            False: 引数 numberが素数ではない
            計算量: sqrt(number)
        */
        for (ll i = 2; i * i <= number; i++) {
            if (number % i == 0) return false;
        }
        return number != 1;
    }

    vector<ll> divisor(ll number) {
        /*
            数字 numberの約数を小さい順に列挙
            計算量: sqrt(number);

        */
        vector<ll> res;

        for (ll i = 1; i * i <= number; i++) {

            if (number % i == 0) {
                res.push_back(i);
                if (i * i != number) {
                    res.push_back(number / i);
                }
            }
        }
        return res;
    }

    vector<P> prime_factor_as_vect(ll number) {
        // 素因数分解


        vector<P> ret;
        for (ll i = 2; i * i <= number; i++) {
            ll count = 0;
            while (number % i == 0) {
                count++;
                number = number / i;
            }
            if (count != 0) ret.push_back(P(i, count));
        }
        if (number != 1) ret.push_back(P(number, 1));

        return ret;
    }

    map<ll, ll> prime_factor_as_map(ll number) {
        map<ll, ll> ret;

        for (ll i = 2; i * i <= number; i++) {
            ll count = 0;
            while (number % i == 0) {
                count++;
                number = number / i;
            }
            ret[i] = count;
        }

        if (number != 1) ret[number] = 1;

        return ret;
    }

    /*
       N以下の素数を列挙する。
    */
    vector<int> Eratosthenes(int N) {
        vector<int> prime_list;

        bool *is_prime = new bool[N + 1];
        fill(is_prime, is_prime + N, true);

        for (int i = 2; i <= N; i++) {
            if (is_prime[i]) {
                prime_list.push_back(i);

                for (int j = 1; j * i <= N; j++) {
                    is_prime[i * j] = false;
                }
            }
        }
        delete is_prime;
        return prime_list;
    }
}  // namespace prime_number


namespace accumulation {


    template <typename T>
    vector<vector<T>> accumlates_2d(vector<vector<T>> &info) {
        /*
            第１列及び第1行は必ず0ベクトルであることが前提
        */
        vector<vector<T>> ret(info.size(), vector<T>(info[0].size(), 0));
        int H = info.size() - 1;
        int W = info[0].size() - 1;
        // cerr << " : " << H << " " << W;

        rep(i, 1, H) {
            rep(j, 1, W) {
                ret[i][j] = ret[i - 1][j] + ret[i][j - 1] - ret[i - 1][j - 1] + info[i][j];
            }
        }
        return ret;
    }

    template <typename T>
    T culmulativesum_2d(vector<vector<T>> &s, int from_x, int from_y, int to_x, int to_y) {
        /*
            第１列及び第1行は必ず0ベクトルであることが前提
        */
        return s[to_x][to_y] - s[from_x - 1][to_y] - s[to_x][from_y - 1] + s[from_x - 1][from_y - 1];
    }
}  // namespace accumulation

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
    cout << pow(10, 5);
}
