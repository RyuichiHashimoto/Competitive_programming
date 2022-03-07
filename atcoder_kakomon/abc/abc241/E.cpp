#include <bits/stdc++.h>

#include <iostream>
using namespace std;

typedef unsigned long long ll;


#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

const int MAX_N = 1E5;

int main(void) {

    ll N, K;
    cin >> N >> K;

    vector<ll> A(N + 1);
    vector<ll> SUM(N + 2);
    vector<ll> POS(N + 2);
    map<ll, ll> find_flag;
    rep(i, 1, N) {
        cin >> A[i - 1];
    }

    ll idx = 0;
    ll result = 0;


    bool first_flag = false;
    rep(i, 1, K) {
        if (find_flag[idx] != 0 && (!first_flag) && 1) {
            ll start = find_flag[idx];
            ll time = (K - start) / (i - start);

            // cout << K - start << " " << i - start << endl;
            // cout << time << " " << result << SUM[POS[start - 1]] << endl;

            if (start == 1) {
                result += (result - 0) * (time - 1);
            } else {
                result += (result - SUM[POS[start - 1]]) * (time - 1);
            }
            i += (i - start) * (time - 1) - 1;

            first_flag = true;
        } else {
            result += A[idx];

            if (!first_flag) {
                find_flag[idx] = i;
                SUM[idx] = result;
                POS[i] = idx;
            }
            idx = result % N;
        }
    }
    // cout << "asd";
    cout << result << endl;
}