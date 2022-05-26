#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;
typedef long long ll;

const int MAX_E = 3001;
ll dp[MAX_E][MAX_E];
ll mod = 998244353;
int main() {

    int N, M;
    cin >> N;
    fill(dp[0], dp[MAX_E], 0);

    vector<ll> A(N + 1), B(N + 1);
    rep(i, 1, N) cin >> A[i];
    rep(i, 1, N) cin >> B[i];


    rep(i, A[1], B[1]) {
        dp[1][i] = 1;
    }

    rep(i, 2, N) {
        int start_point = max(A[i], A[i - 1]);
        int end_point = B[i];

        rep(j, A[i - 1], start_point) {
            dp[i][start_point] += dp[i - 1][j];
            dp[i][start_point] %= mod;
        }

        rep(j, start_point + 1, end_point) {
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }

    rep(i, 1, 10) {
        rep(j, 1, 10) {
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    ll ret = 0;

    rep(i, 0, MAX_E) {
        ret += dp[N][i];
        ret %= mod;
    }
    cout << ret;
}