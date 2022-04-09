#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<int, int> P;


int dp[20001][256];

int main(void) {

    int INF = 1 << 30;
    cout << INF << endl;
    while (true) {
        int n, m;

        cin >> n >> m;
        if (n == 0 && m == 0) {
            return 0;
        }

        vector<int> set(m);
        vector<int> map(n);

        rep(i, 1, m) {
            cin >> set[i - 1];
        }

        rep(i, 1, n) {
            cin >> map[i - 1];
        }

        fill(dp[0], dp[20001], INF);
        dp[0][128] = 0;

        rep(i, 1, n) {
            rep(j, 0, 255) {
                if (dp[i - 1][j] != INF) {
                    for (auto s : set) {
                        int next_val = max(min(j + s, 255), 0);
                        // cout << next_val << endl;
                        int diff = (map[i - 1] - next_val) * (map[i - 1] - next_val);
                        dp[i][next_val] = min(dp[i - 1][j] + diff, dp[i][next_val]);
                        // cout << dp[i][next_val] << " " << i << " " << j << endl;
                    }
                }
            }
        }
        int min_ = INF;
        rep(i, 0, 255) {

            min_ = min(min_, dp[n][i]);
        }
        cout << min_ << endl;
    }
}
