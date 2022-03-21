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

    int N, D;

    cin >> N >> D;

    vector<int> A(N);

    rep(i, 0, N - 1) {
        cin >> A[i];
    }

    vector<int> min_temp(N), max_temp(N), C(N);

    rep(i, 0, N - 1) {
        cin >> min_temp[i] >> max_temp[i] >> C[i];
    }

    int dp[201][201];

    fill(dp[0], dp[201], 0);

    rep(i, 1, N - 1) {
    }
}
