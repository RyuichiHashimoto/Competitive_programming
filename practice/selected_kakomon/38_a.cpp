#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<int, int> P;


int main(void) {
    int n;
    cin >> n;

    int dp[1001][1001];

    rep(i, 1, n) {
        string a, b;
        cin >> a >> b;
        fill(dp[0], dp[1001], 0);

        rep(a_i, 1, a.size()) {
            dp[a_i][0] = dp[a_i - 1][0];

            rep(b_i, 1, b.size()) {
                if (a[a_i - 1] == b[b_i - 1]) {
                    dp[a_i][b_i] = dp[a_i - 1][b_i - 1] + 1;
                } else {
                    // dp[a_i][b_i] = dp[a_i - 1][b_i];
                    dp[a_i][b_i] = min(dp[a_i][b_i - 1], dp[a_i - 1][b_i]);
                }
            }
        }


        cout << dp[a.size()][b.size()] << endl;
    }
}
