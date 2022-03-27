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


    int N, M;
    cin >> N >> M;


    vector<ll> A(N + 1), B(M + 1), C(M + N + 1);

    rep(i, 0, N) {
        cin >> A[i];
        // cout << A[i] << " ";
    }
    // cout << endl;
    rep(i, 0, N + M) {
        cin >> C[i];
        // cout << C[i] << " ";
    }

    reverse(A.begin(), A.end());
    reverse(C.begin(), C.end());


    B[0] = C[0] / A[0];


    rep(i, 1, M) {
        B[i] = C[i];

        rep(j, 0, i - 1) {
            if (i - j <= N) {
                B[i] -= B[j] * A[i - j];
            }
        }

        B[i] /= A[0];
    }

    reverse(B.begin(), B.end());
    rep(i, 0, M) {
        cout << B[i] << " ";
    }
}
