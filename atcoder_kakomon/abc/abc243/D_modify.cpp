#include <bits/stdc++.h>

#include <iostream>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;


int main(void) {
    int N;
    ll X;
    string S;

    cin >> N >> X >> S;

    vector<int> vec(N + 1);

    int idx;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') {
            vec[idx++] = 0;
        } else if (S[i] == 'R') {
            vec[idx++] = 1;
        } else if (S[i] == 'U') {
            if (vec[idx - 1] == -1 or (idx == 0)) {
                vec[idx++] = -1;
            } else {
                idx--;
            }
        }
    }
    // cout << idx << endl;
    for (int i = 0; i < idx; i++) {
        if (vec[i] == -1) {
            X = X / 2;
        } else if (vec[i] == 0) {
            X = X * 2;
        } else if (vec[i] == 1) {
            X = X * 2 + 1;
        }
    }
    cout << X;
}