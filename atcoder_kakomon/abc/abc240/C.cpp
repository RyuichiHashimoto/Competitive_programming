#include <bits/stdc++.h>

#include <iostream>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

const int MAX_N = 1.0E4;

ll diff[MAX_N];

int dp[101][MAX_N + 1];

int main(void) {


    int N, X;
    cin >> N >> X;
    vector<int> a(N + 1), b(N + 1);

    rep(i, 1, N) {
        cin >> a[i] >> b[i];
    }
    fill(dp[0], dp[101], 0);

    dp[1][a[1]] = 1;
    dp[1][b[1]] = 1;
    


    for (int i = 2; i <= N; i++) {
        rep(j, 1, X) {
            if (j >= a[i]) {
                // cout << i << " " << j << " " << dp[i - 1][j - a[i]] << endl;

                dp[i][j] = dp[i - 1][j - a[i]];
            }
            if (j >= b[i] && (dp[i][j] == 0)) {
                dp[i][j] = dp[i - 1][j - b[i]];
            }
        }
    }
    rep(i, 1, N) {
        rep(j, 1, X) {
            // cout << dp[i][j] << " ";
        }
        // cout << endl
    }


    if (dp[N][X] == 1) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}