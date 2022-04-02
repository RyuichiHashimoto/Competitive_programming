
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

int jangle[1001][1001];
int ocan[1001][1001];
int ice[1001][1001];

int jangle_ruiseki[1001][1001];
int ocan_ruiseki[1001][1001];
int ice_ruiseki[1001][1001];

int calc(int a, int b, int c, int d, int s[1001][1001]) {
    return s[c][d] - s[a - 1][d] - s[c][b - 1] + s[a - 1][b - 1];
}

int main(void) {

    int n, m;
    cin >> n >> m;

    fill(jangle[0], jangle[1001], 0);
    fill(ocan[0], ocan[1001], 0);
    fill(ice[0], ice[1001], 0);

    fill(jangle_ruiseki[0], jangle_ruiseki[1001], 0);
    fill(ocan_ruiseki[0], ocan_ruiseki[1001], 0);
    fill(ice_ruiseki[0], ice_ruiseki[1001], 0);

    int k;
    cin >> k;

    rep(i, 1, n) {
        string name;
        cin >> name;
        rep(j, 1, m) {

            if (name[j - 1] == 'J') {
                jangle[i][j] = 1;
            } else if (name[j - 1] == 'I') {
                ice[i][j] = 1;
            } else if (name[j - 1] == 'O') {
                ocan[i][j] = 1;
            }
        }
    }

    rep(i, 1, n) {
        rep(j, 1, m) {
            jangle_ruiseki[i][j] = jangle_ruiseki[i - 1][j] + jangle_ruiseki[i][j - 1] - jangle_ruiseki[i - 1][j - 1] + jangle[i][j];
            ocan_ruiseki[i][j] = ocan_ruiseki[i - 1][j] + ocan_ruiseki[i][j - 1] - ocan_ruiseki[i - 1][j - 1] + ocan[i][j];
            ice_ruiseki[i][j] = ice_ruiseki[i - 1][j] + ice_ruiseki[i][j - 1] - ice_ruiseki[i - 1][j - 1] + ice[i][j];
        }
        }

    int a, b, c, d;
    rep(i, 1, k) {
        cin >> a >> b >> c >> d;
        cout << calc(a, b, c, d, jangle_ruiseki) << " " << calc(a, b, c, d, ocan_ruiseki) << " " << calc(a, b, c, d, ice_ruiseki) << endl;
    }
}
