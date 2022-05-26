
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

int dp[101][101];
int A[101], B[101];
void dfs(int a, int b) {

    rep(i, a, b - 1) {

        if (i == a) {
            if (dp[i + 1][b] == INT_MAX / 2) {
                dfs(i + 1, b);
            }
            dp[a][b] = min(dp[a][b], dp[i + 1][b] + A[i] * B[i] * B[b]);
        } else if (i == b - 1) {
            if (dp[a][i] == INT_MAX / 2) {
                dfs(a, i);
            }

            dp[a][b] = min(dp[a][b], dp[a][i] + A[a] * B[i] * B[b]);
        } else {
            if (dp[a][i] == INT_MAX / 2) {
                dfs(a, i);
            }
            if (dp[i + 1][b] == INT_MAX / 2) {
                dfs(i + 1, b);
            }


            dp[a][b] = min(dp[a][b], dp[a][i] + dp[i + 1][b] + A[a] * B[i] * B[b]);
            // dp[a][b] = min(dp[a][b], dp[a][i] + dp[i + 1][b] + A[a] * A[i + 1] * B[b]);
        }
    }
}

int main(void) {
    int n;

    cin >> n;

    fill(A, A + 101, 0);
    fill(B, B + 101, 0);
    fill(dp[0], dp[101], INT_MAX / 2);

    rep(i, 1, n) {
        cin >> A[i] >> B[i];
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    } else if (n == 2) {
        cout << A[1] * A[2] * B[2] << endl;

        return 0;
    }

    rep(i, 1, n) {
        dp[i][i] = 0;
    }


    rep(i, 1, n - 1) {
        dp[i][i + 1] = A[i] * A[i + 1] * B[i + 1];
    }

    dfs(1, n);
    cout << dp[1][n] << endl;
    // cout << dp[1][3] << endl;
}
