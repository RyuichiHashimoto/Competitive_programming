#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;


int main(void) {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);

    rep(i, 1, N) {
        cin >> A[i - 1];
    }
    rep(i, 1, N) {
        cin >> B[i - 1];
        B[i - 1] = B[i - 1];
    }
    rep(i, 1, N) {
        cin >> C[i - 1];
        C[i - 1] = C[i - 1];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll sum = 0;
    rep(i, 0, N - 1) {
        int val = B[i];
        auto ai = upper_bound(A.begin(), A.end(), val - 1);
        auto ci = lower_bound(C.begin(), C.end(), val + 1);

        if (ci == C.end()) {
            continue;
        }
        if (ai != A.begin()) {
            ai--;
        } else {
            continue;
        }

        sum += (ai - A.begin() + 1) * (C.end() - ci);
    }
    cout << sum << endl;
}