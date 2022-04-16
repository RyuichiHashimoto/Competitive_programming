
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
#define inrange(val, from, to) (from <= val) and (val <= to)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

typedef pair<ll, ll> P;

ll dp[3000][3000];
ll mod = 998244353;

int main(void) {

    ll N, M, K;

    cin >> N >> M >> K;


    fill(dp[0], dp[3000], 0);

    for (int i = 1; i <= M; i++) {
        dp[1][i] = 1;
    }

    rep(i, 1, N) {
        ll sum_ = 0;
        rep(j, 1, K) {
            rep(m, 1, M) {
                dp[i + 1][j + m] += dp[i][j];
                dp[i + 1][j + m] %= mod;
            }
        }
    }


    ll ret = 0;
    rep(i, 1, K) {
        ret += dp[N][i];
        ret %= mod;
    }
    cout << ret << endl;


    return 0;
}
