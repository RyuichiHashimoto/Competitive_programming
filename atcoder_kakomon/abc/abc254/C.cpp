#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

typedef long long ll;
#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;


int main() {

    int N, K;

    cin >> N >> K;

    vector<int> A(N);
    vector<vector<int>> each(K, vector<int>(0, N));

    rep(i, 0, N - 1) {
        int idx = i % K;

        int val;
        cin >> val;
        each[idx].push_back(val);
    }

    rep(i, 0, K - 1) {
        sort(each[i].begin(), each[i].end());
    }

    rep(i, 0, N - 1) {
        int k_idx = i % K;
        int idx = i / K;

        A[i] = each[k_idx][idx];
    }
    rep(i, 1, N - 1) {
        if (A[i] - A[i - 1] < 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}