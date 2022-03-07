#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

int main(void) {

    vector<int> A(10);

    rep(i, 0, 10) {
        cin >> A[i];
    }
    int idx = 0;
    for (int i = 0; i < 3; i++) {

        idx = A[idx];
    }

    cout << idx << endl;
}