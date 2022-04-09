#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

int main(void) {

    ll N;
    cin >> N;

    vector<ll> A(N), B(N);

    ll distance = 0;
    rep(i, 1, N) {
        cin >> A[i - 1] >> B[i - 1];
        distance += abs(A[i - 1] - B[i - 1]);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll mid_A = A[A.size() / 2];
    ll mid_B = B[B.size() / 2];

    rep(i, 0, N - 1) {
        distance += abs(A[i] - mid_A);
        distance += abs(B[i] - mid_B);
    }
    cout << distance << endl;
}