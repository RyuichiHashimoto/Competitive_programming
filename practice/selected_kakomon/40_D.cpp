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

    ll dp[101][10];

    dp[2][1] = 1;  // 1 1
    dp[2][2] = 1;  // 1 2
    dp[2][3] = 1;  // 1 3

    dp[2][4] = 1;  // 2 1
    dp[2][5] = 1;  // 2 2
    dp[2][6] = 1;  // 2 3

    dp[2][7] = 1;  // 3 1
    dp[2][8] = 1;  // 3 2
    dp[2][9] = 1;  // 3 3

    int N, K;
    cin >> N >> K;

    vector<P> vec(K);


    rep(i, 1, K) {
        cin >> vec[i - 1].first >> vec[i - 1].second;
    }

    sort(vec.begin(), vec.end());
    int counter = 0;

    for (counter = 0;; counter++) {
        if (vec[counter].first > 2) {
            break;
        }
        if (vec[counter].first == 2) {
            rep(j, 1, 9) {
                if (((j - 1) % 3) + 1 != vec[counter].second) {
                    dp[2][j] = 0;
                }
            }
        }

        if (vec[counter].first == 1) {
            rep(j, 1, 9) {
                if ((j - 1) / 3 + 1 != vec[counter].second) {
                    dp[2][j] = 0;
                }
            }
        }
    }

    rep(i, 3, N) {

        dp[i][1] = dp[i - 1][4] + dp[i - 1][7];
        dp[i][2] = dp[i - 1][1] + dp[i - 1][4] + dp[i - 1][7];
        dp[i][3] = dp[i - 1][1] + dp[i - 1][4] + dp[i - 1][7];

        dp[i][4] = dp[i - 1][2] + dp[i - 1][5] + dp[i - 1][8];
        dp[i][5] = dp[i - 1][2] + dp[i - 1][8];
        dp[i][6] = dp[i - 1][2] + dp[i - 1][5] + dp[i - 1][8];

        dp[i][7] = dp[i - 1][3] + dp[i - 1][6] + dp[i - 1][9];
        dp[i][8] = dp[i - 1][3] + dp[i - 1][6] + dp[i - 1][9];
        dp[i][9] = dp[i - 1][3] + dp[i - 1][6];


        if (vec[counter].first == i) {
            rep(j, 1, 9) {
                if (((j - 1) % 3) + 1 != vec[counter].second) {
                    dp[i][j] = 0;
                }
            }
            counter++;
        }
        rep(j, 1, 9) {
            dp[i][j] = dp[i][j] % 10000;
            // sum_ = (sum_ + dp[N][j]) % 10000;
        }
    }
    int sum_ = 0;

    rep(j, 1, 9) {
        sum_ = (sum_ + dp[N][j]) % 10000;
        // sum_ = (sum_ + dp[N][j]) % 10000;
    }
    cout << sum_ << endl;
}
