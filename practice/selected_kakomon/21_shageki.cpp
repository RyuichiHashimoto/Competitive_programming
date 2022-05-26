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


int main(void) {

    int N;
    cin >> N;

    vector<ll> H(N), S(N);

    rep(i, 1, N) {
        cin >> H[i - 1] >> S[i - 1];
    }

    ll min_val = 0x7FFFFFFFFFFFFFFF;

    ll left = 0;
    ll right = min_val / 2;

    while (right - left != 1) {

        ll mid = (left + right) / 2;

        vector<ll> X(N);
        bool is_suit = true;
        rep(i, 0, N - 1) {
            if (mid < H[i]) {
                is_suit = false;
            }
            X[i] = (mid - H[i]) / S[i];
        }
        sort(X.begin(), X.end());

        rep(i, 0, N - 1) {
            if (X[i] < i) {
                is_suit = false;
                break;
            }
        }
        if (is_suit) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << endl;
}