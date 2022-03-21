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

int dp[3001][5];

int main(void) {

    int n;

    cin >> n;

    int Black = 1, Red = 2, Blue = 3, White = 4;

    int color[1001][5];

    fill(color[0], color[1001], 0);
    fill(dp[0], dp[3001], INT_MAX / 4);

    rep(i, 1, 5) {
        string name;
        cin >> name;

        rep(j, 1, name.size()) {
            if (name[j - 1] == 'R') {
                color[j][Red]++;
            } else if (name[j - 1] == 'B') {
                color[j][Blue]++;
            } else if (name[j - 1] == 'W') {
                color[j][White]++;
            } else if (name[j - 1] == '#') {
                color[j][Black]++;
            }
        }
    }

    // dp[1][Black] = 5 - color[1][]

    rep(i, 1, 4) {
        dp[1][i] = 5 - color[1][i];
    }


    rep(i, 2, n) {
        rep(j, 2, 4) {
            rep(k, 2, 4) {
                if (j != k) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + 5 - color[i][j]);
                }
            }
        }
    }

    int min_ = INT_MAX;

    rep(i, 2, 4) {
        min_ = min(min_, dp[n][i]);
    }
    cout << min_ << endl;
}
