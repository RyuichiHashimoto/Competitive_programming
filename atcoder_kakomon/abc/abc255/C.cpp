#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

typedef long long ll;
#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;


int main() {

    ll X, A, D, N;

    cin >> X >> A >> D >> N;


    ll first_val = A;
    ll last_val = A + D * (N - 1);

    // cout << first_val << " " << last_val;

    if (D > 0) {
        if (first_val >= X) {
            cout << abs(first_val - X);
            return 0;
        }

        if (last_val <= X) {
            cout << abs(X - last_val);
            return 0;
        }
    } else if (D < 0) {
        if (first_val < X) {
            cout << abs(X - first_val);
            return 0;
        }

        if (last_val > X) {
            cout << abs(last_val - X);
            return 0;
        }
    } else if (D == 0) {
        cout << abs(A - X);
        return 0;
    }

    ll from = (X - A) / D;
    ll to = (X - A) / D + 1;

    ll from_dif = abs(from * D + A - X);
    ll to_dif = abs(to * D + A - X);


    cout << min(from_dif, to_dif) << endl;
    return 0;
}
