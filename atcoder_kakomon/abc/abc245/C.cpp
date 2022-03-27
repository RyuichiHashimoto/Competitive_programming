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

    int N, K;

    cin >> N >> K;
    vector<int> A(N), B(N);

    rep(i, 0, N - 1) {
        cin >> A[i];
    }
    rep(i, 0, N - 1) {
        cin >> B[i];
    }

    bool can[2];
    can[0] = true;
    can[1] = true;
    bool next[2];


    rep(i, 1, N - 1) {

        next[0] = false;
        next[1] = false;

        if (can[0]) {
            if (abs(A[i] - A[i - 1]) <= K) {
                next[0] = true;
            }
            if (abs(B[i] - A[i - 1]) <= K) {
                next[1] = true;
            }
        }
        if (can[1]) {
            if (abs(A[i] - B[i - 1]) <= K) {
                next[0] = true;
            }
            if (abs(B[i] - B[i - 1]) <= K) {
                next[1] = true;
            }
        }

        can[0] = next[0];
        can[1] = next[1];
    }

    if (can[0] or can[1]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
