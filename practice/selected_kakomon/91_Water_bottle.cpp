
#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<ll, ll> P;
const ll MAX_N = 1.0E5;
// const ll ll_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

typedef pair<ll, ll> P;

int main(void) {

    double a, b, x;

    cin >> a >> b >> x;

    double max_ = a * a * b;

    if (max_ < 2 * x) {
        double tan_sheta = 2 * (max_ - x) / (a * a * a);
        cout << setprecision(10) << atan(tan_sheta) * (180 / M_PI) << endl;
    } else {
        double tan_sheta = 2 * x / (a * b * b);
        cout << setprecision(10) << 90 - atan(tan_sheta) * (180 / M_PI) << endl;
    }
}
