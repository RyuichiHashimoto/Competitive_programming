#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

int A[10001001];
int B[10001001];
int darts[1001];
int main(void) {

    int N, M;
    cin >> N >> M;

    N++;
    int a = 0;
    fill(darts, darts + 1000, 0);

    rep(i, 1, N) {
        cin >> darts[i];
    }

    rep(i, 0, N - 1) {
        rep(j, 0, N - 1) {
            A[i * N + j] = darts[i] + darts[j];
            B[i * N + j] = darts[i] + darts[j];
        }
    }
    sort(A, A + N * N);
    rep(i, 0, N * N - 1) {
        // cout << A[i] << " ";
    }
    // cout << endl;

    int max_val = -1;
    rep(i, 0, N * N - 1) {
        if (M < A[i]) {
            continue;
        } else {
            auto s = lower_bound(A, A + N * N, M - A[i]);
            if (*s != A[0]) {
                s--;
            }
            if (*(s) + A[i] <= M) {
                max_val = max(max_val, *(s) + A[i]);
            }
        }
    }
    cout << max_val << endl;
}