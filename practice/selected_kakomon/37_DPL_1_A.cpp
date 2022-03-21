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
    int n, m;
    cin >> n >> m;

    vector<int> A(m);
    rep(i, 1, m) {
        cin >> A[i - 1];
    }

    sort(A.begin(), A.end());

    int dp[50001];
    fill(dp, dp + 50001, 5000000000);

    dp[0] = 0;

    rep(i, 1, n) {
        rep(j, 1, m) {
            if ((i - A[j - 1] >= 0)) {
                dp[i] = min(dp[i], dp[i - A[j - 1]] + 1);
            }
        }
    }
    cout << dp[n] << endl;
}
