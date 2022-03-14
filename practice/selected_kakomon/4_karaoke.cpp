#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

int main(void) {

    int N, M;
    cin >> N >> M;
    vector<vector<ll>> A(N + 1);
    rep(i, 1, N) {
        A[i].resize(M + 1);
        rep(j, 1, M) {
            cin >> A[i][j];
        }
    }

    ll max_ = -1;
    rep(i, 1, M) {

        rep(j, i + 1, M) {
            ll big = 0;
            rep(k, 1, N) {
                big += max(A[k][i], A[k][j]);
            }

            max_ = max(max_, big);
        }
    }
    cout << max_ << endl;
}