
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF / 2ll;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)


ll dp[1001][1 << 3];

int ch2i(char s) {

    if (s == 'J') {
        return 2;
    } else if (s == 'O') {
        return 1;
    } else {
        return 0;
    }
}


int main(void) {

    int N;
    cin >> N;
    string member;
    cin >> member;

    fill(dp[0], dp[1001], 0);


    int J = 2, O = 1, I = 0;


    rep(i, 0, (1 << 3) - 1) {
        if ((i & (1 << J)) && (i & (1 << ch2i(member[0])))) {
            dp[0][i] = 1;
        }
    }

    int mod = 10007;
    rep(i, 1, N - 1) {
        rep(current_day, 1, (1 << 3) - 1) {
            if (current_day & (1 << ch2i(member[i]))) {
                rep(before_day, 1, (1 << 3) - 1) {
                    if ((before_day & current_day) != 0) {
                        dp[i][current_day] += dp[i - 1][before_day];
                        dp[i][current_day] = dp[i][current_day] % mod;
                        // cout <
                    }
                }
            }
        }
    }
    int ret = 0;
    rep(i, 1, (1 << 3)) {
        ret += dp[N - 1][i];
        ret %= 10007;
    }
    cout << ret << endl;
}
