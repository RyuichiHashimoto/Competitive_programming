#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
// const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<int, int> P;

const int MAX_N = 1E6 + 1;
int dp[MAX_N];

int main(void) {


    int seisimentai[2001];

    int counter = 1;

    int i = 1;

    for (i = 1; i * (i * 1) * (i * 2) <= 6e6; i++) {
        seisimentai[i] = i * (i + 1) * (i + 2) / 6;
    }
    int n = --i;
    reverse(seisimentai + 1, seisimentai + n + 1);

    int s;
    while (true) {
        cin >> s;
        if (s == 0) {
            break;
        }
        fill(dp, dp + MAX_N, INT_MAX / 2);

        dp[0] = 0;
        for (int i = 1; i <= min(s, n); i++) {
            dp[i][j] = 1;
        }

        rep(i, 2, min(s, n)) {
            rep(j, 1, s) {
                if (j - seisimentai[i] >= 0) {
                    dp[j] = min(dp[j], dp[j - seisimentai[i]] + 1);
                }
            }
        }
        int ans1 = dp[s];
        fill(dp, dp + MAX_N, INT_MAX / 2);

        dp[0] = 0;


        // rep(i, 1, s) {
        // cout << dp[i] << " ";
        // }
        // cout << endl;


        cout << ans1 << " " << dp[s] << endl;
    }
    return 0;
}
