#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int MAX_N = 1.0E5;
typedef pair<int, int> P;

bool used[5001][5001];

int main(void) {

    int N;
    cin >> N;

    fill(used[0], used[5001], false);

    vector<ll> A(N + 1), B(N + 1);

    rep(i, 1, N) {
        ll a, b;
        cin >> a >> b;
        used[a][b] = true;
        A[i] = a;
        B[i] = b;
    }

    ll max_distance = 0;
    rep(i, 1, N) {
        rep(j, i + 1, N) {

            ll x = -1 * (A[i] - A[j]);
            ll y = B[i] - B[j];

            if ((A[i] + y <= 5000) && (B[i] + x <= 5000) && (A[i] + y >= 0) && (B[i] + x >= 0)) {
                if ((A[j] + y <= 5000) && (B[j] + x <= 5000) && (A[j] + y >= 0) && (B[j] + x >= 0)) {
                    if (used[A[i] + y][B[i] + x] && used[A[j] + y][B[j] + x]) {
                        max_distance = max(max_distance, x * x + y * y);
                    }
                }
            }

            if ((A[i] - y <= 5000) && (B[i] - x <= 5000) && (A[i] - y >= 0) && (B[i] - x >= 0)) {
                if ((A[j] - y <= 5000) && (B[j] - x <= 5000) && (A[j] - y >= 0) && (B[j] - x >= 0)) {
                    if (used[A[i] - y][B[i] - x] && used[A[j] - y][B[j] - x]) {
                        max_distance = max(max_distance, x * x + y * y);
                    }
                }
            }
        }
    }
    if (max_distance == 0) {
        cout << max_distance << endl;
    } else {
        cout << max_distance << endl;
    }
}