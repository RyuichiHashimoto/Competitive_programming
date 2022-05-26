#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;

vector<int> V[10000];

typedef long long ll;

ll pow(ll x, ll n, ll mod) {

    ll res = 1;

    while (n > 0) {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n = n >> 1;
    }
    return res;
}

const int MAX_E = 1E6 + 1;
ll dp[MAX_E][4];

int main() {
    ll H, W, K;
    ll x1, y1, x2, y2;
    ll mod = 998244353;

    cin >> H >> W >> K;
    cin >> x1 >> y1 >> x2 >> y2;

    fill(dp[0], dp[MAX_E], 0);

    int answer = 0;
    int near_x = 1;
    int near_y = 2;
    int other = 3;


    if (x1 == x2 && y1 == y2) {
        dp[0][answer] = 1;
    } else if (x1 == x2) {

        dp[0][near_y] = 1;
    } else if (y1 == y2) {
        dp[0][near_x] = 1;
    } else {
        dp[0][other] = 1;
    }


    //  cout << dp[0][near_x] << " " << dp[0][near_y] << endl;
    rep(i, 1, K) {
        dp[i][answer] = (dp[i - 1][near_x] + dp[i - 1][near_y]) % mod;

        dp[i][near_x] = dp[i - 1][other];
        dp[i][near_x] += (dp[i - 1][answer] * (H - 1)) % mod;
        dp[i][near_x] += (dp[i - 1][near_x] * (H - 2)) % mod;


        dp[i][near_y] = dp[i - 1][other];
        dp[i][near_y] += (dp[i - 1][answer] * (W - 1)) % mod;
        dp[i][near_y] += (dp[i - 1][near_y] * (W - 2)) % mod;

        dp[i][other] += dp[i - 1][near_x] * (W - 1);
        dp[i][other] %= mod;
        dp[i][other] += dp[i - 1][near_y] * (H - 1);
        dp[i][other] %= mod;
        dp[i][other] += (dp[i - 1][other] * (H - 2 + W - 2)) % mod;
        dp[i][other] %= mod;
        //   dp[i][other] += (s * (W - 2)) % mod;

        //   cout << dp[i][answer] << " " << dp[i][near_x] << " " << dp[i][near_y] << " " << dp[i][other] << endl;
    }
    cout << dp[K][answer];
}