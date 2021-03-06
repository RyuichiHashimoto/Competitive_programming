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

    int dp[101][10001];
    int N, W;
    cin >> N >> W;


    fill(dp[0], dp[101], -1);
    dp[0][0] = 0;

    int min_val = -1;
    int a, b;
    rep(i, 1, N) {
        cin >> a >> b;

        rep(j, 0, W) {
            dp[i][j] = dp[i - 1][j];

            if (dp[i - 1][j - b] != -1) {
                if (j - b >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - b] + a);
                    min_val = max(min_val, dp[i][j]);
                }
            }
            if (dp[i][j - b] != -1) {
                if (j - b >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - b] + a);
                    min_val = max(min_val, dp[i][j]);
                }
            }
        }
    }

    cout << min_val << endl;
}
