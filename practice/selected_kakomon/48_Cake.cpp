
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
typedef tuple<int, int, ll, bool> tp;

ll dp[1001][1001];
ll A[2001];

void dfs(vector<int> &array, int from, int to) {
    if (from == to) {
        return;
    }
    if (to - from == 1) {
        if (abs(array[to] - array[from]) <= 1) {
            dp[from][to] = 2;
        }
        return;
    }


    rep(i, from, to) {
        rep(j, i + 2, to) {
            dfs(array, i + 1, j - 1);

            if (dp[i + 1][j - 1] != 0 && abs(array[i] - array[j] <= 1)) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
        }
    }
}

int main(void) {
    int n;


    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<int> Array(n + 1);
        rep(i, 1, n) {
            cin >> Array[i];
        }

        fill(dp[0], dp[1001], 0);

        dfs(Array, 1, n);
        cout << dp[1][n] << endl;
    }
}
