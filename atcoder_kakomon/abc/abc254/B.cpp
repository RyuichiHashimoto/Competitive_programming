#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;
typedef long long ll;

const int MAX_E = 3001;
typedef pair<int, int> P;

ll dp[100][100];

ll bits_msb(ll v) {
    int count = 0;
    if (v == 0) return 0;

    while (v != 0) {
        v = v >> 1;
        count++;
    }
    return count;
}

int main() {

    ll val[31][31];

    int N;
    cin >> N;

    rep(i, 1, N) {
        rep(j, 1, i) {
            if (j == 1 || j == i) {
                val[i][j] = 1;
            } else {
                val[i][j] = val[i - 1][j - 1] + val[i - 1][j];
            }
        }
    }

    rep(i, 1, N) {
        rep(j, 1, i) {
            cout << val[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}