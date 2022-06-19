#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;
typedef long long ll;

const int MAX_E = 3001;
typedef pair<int, int> P;


int main() {

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> ruiseki(N + 1);

    rep(i, 1, N) {
        cin >> A[i - 1];
    }

    for (int i = N - 1; i >= 0; i--) {
        ruiseki[i] = ruiseki[i + 1] + A[i];
    }

    int counter = 0;
    rep(i, 1, N) {
        if (ruiseki[i - 1] >= 4) {
            counter++;
        }
    }
    cout << counter;
}