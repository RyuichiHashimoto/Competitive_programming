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

int dp[2001][2001];
int item[2001][2001];

int main(void) {

    int items, days;


    fill(dp[0], dp[2001], 0);
    fill(item[0], item[2001], -1);

    cin >> days >> items;

    vector<int> max_temp(days + 1);

    vector<int> lower(items + 1), upper(items + 1), hade(items + 1);

    rep(i, 1, days) {
        cin >> max_temp[i];
    }

    rep(i, 1, items) {
        cin >> lower[i] >> upper[i] >> hade[i];
    }


    rep(i, 2, days) {
        rep(j, 1, items) {
            if ((lower[j] <= max_temp[i]) && (upper[j] >= max_temp[i])) {
                rep(k, 1, items) {
                    if ((lower[k] <= max_temp[i - 1]) && (upper[k] >= max_temp[i - 1])) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(hade[k] - hade[j]));
                    }
                }
            }
        }
    }

    int ret = -1;
    rep(i, 1, items) {
        ret = max(ret, dp[days][i]);
    }
    cout << ret << endl;
}
