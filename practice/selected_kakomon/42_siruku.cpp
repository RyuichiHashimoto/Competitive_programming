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

int dp[3001][3001];

int main(void) {

    int sites, days;

    cin >> sites >> days;

    vector<int> distance(sites + 1);
    vector<int> weather(days + 1);

    rep(i, 1, sites) {
        cin >> distance[i];
    }
    rep(i, 1, days) {
        cin >> weather[i];
    }


    int INF = 0x4FFFFFFF;
    // cout << INF;

    fill(dp[0], dp[3001], INF);

    dp[0][0] = 0;  // i日目にj番目の都市にいるときのコストの最小値　

    rep(i, 1, days) {
        rep(j, 0, sites) {
            dp[i][j] = min({dp[i][j], dp[i - 1][j], dp[i - 1][j - 1] + weather[i] * distance[j]});
        }
    }

    cout << dp[days][sites] << endl;
}
