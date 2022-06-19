#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
typedef long long ll;

using namespace std;

ll dp[1010][5010];
ll souwa[5010];
ll mod = 998244353;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    fill(dp[0], dp[1001], 0);
    fill(souwa, souwa + 5010, 0);


    rep(i, 1, M) {
        dp[1][i] = 1;
    }


    rep(i, 2, N) {
        fill(souwa, souwa + 5010, 0);
        rep(j, 1, M) {
            souwa[j] = (dp[i - 1][j] + souwa[j - 1]) % mod;
        }

        if (K == 0) {
            rep(j, 1, M) {
                dp[i][j] = (souwa[M]);
            }
        } else {
            rep(j, 1, M) {
                ll before = 0;
                if (j >= K) {
                    before = souwa[j - K];
                }
                ll after = 0;
                if (j + K <= M) {
                    after = souwa[M] - souwa[j + K - 1];
                    if (after < 0) {
                        after += mod;
                    }
                }
                dp[i][j] = (before + after) % mod;
            }
        }
    }


    ll sum_ = 0;
    rep(i, 1, M) {
        sum_ += dp[N][i];
        sum_ %= mod;
    }
    cout << sum_ << endl;
}