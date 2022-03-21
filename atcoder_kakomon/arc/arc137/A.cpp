#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)


long long GCD(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

bool check(long long a, long long from, long long right) {
    for (ll i = from; i + a <= right; i++) {
        if (GCD(i, i + a) == 1) {
            return true;
        }
    }
    return false;
}

int main(void) {

    ll L, R;

    cin >> L >> R;

    ll left = 0, right = R - L + 1;

    while (right - left > 1) {
        // cout << left << " " << right << endl;

        ll mid = (left + right) >> 1;

        if (check(mid, L, R)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << left << endl;
    cout << (L = 4) << endl;
}
