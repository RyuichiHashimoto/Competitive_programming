
#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<ll, ll> P;
const ll MAX_N = 1.0E5;
// const ll ll_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

typedef pair<ll, ll> P;

vector<int> dp[17];

int main(void) {

    int N;

    cin >> N;


    dp[1].clear();

    dp[1].push_back(1);

    rep(i, 2, N) {
        dp[i].clear();
        for (auto s : dp[i - 1]) {
            dp[i].push_back(s);
        }
        dp[i].push_back(i);

        for (auto s : dp[i - 1]) {
            dp[i].push_back(s);
        }
    }

    for (auto s : dp[N]) {
        cout << s << " ";
    }

    return 0;
}