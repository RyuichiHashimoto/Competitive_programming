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

    vector<int> A(n - 1);
    int ans;
    ll max_ = 0;

    rep(i, 0, n - 2) {
        cin >> A[i];
        max_ += A[i];
    }
    cin >> ans;

    ll dp[101][10021];

    fill(dp[0], dp[101], 0ll);

    dp[0][A[0]] = 1;

    rep(i, 1, n - 1) {
        // cout << A[i] << endl;
        rep(j, 0, max_) {
            if ((j + A[i] <= 20)) {
                dp[i][j + A[i]] += dp[i - 1][j];
            }


            if (j - A[i] >= 0) {
                dp[i][j - A[i]] += dp[i - 1][j];
            }
        }
    }
    rep(i, 0, n - 2) {
        // cout << i << "  " << A[i] << ": ";
        rep(j, 0, max_) {
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    cout << dp[n - 2][ans] << endl;
}
