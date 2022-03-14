#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

typedef pair<int, int> P;


int main(void) {

    ll N;
    cin >> N;
    vector<ll> A(N);

    rep(i, 1, N) {
        cin >> A[i - 1];
    }

    ll M;
    cin >> M;

    rep(i, 1, M) {
        ll target;
        cin >> target;

        // cout << (1ll << N) << endl;
        bool find_flag = false;
        for (ll a = 0; a < (1ll << N); a++) {
            ll counter = 0;
            ll sum = 0;

            while ((a >> counter) != 0) {
                if ((a >> counter) & 1) {
                    sum += A[counter];
                }
                counter++;
            }
            if (sum == target) {
                find_flag = true;
                break;
            }
        }

        if (find_flag) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}