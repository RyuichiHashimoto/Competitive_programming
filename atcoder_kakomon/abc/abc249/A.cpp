
#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<ll, ll> P;
const ll MAX_N = 1.0E5;
// const ll ll_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define inrange(val, from, to) (from <= val) and (val <= to)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)


int main(void) {

    int a, b, c, d, e, f, x;

    cin >> a >> b >> c >> d >> e >> f >> x;

    int A_length = 0;
    int B_length = 0;
    int tmp = x;
    while (tmp > 0) {
        if (tmp >= a) {
            tmp -= a;
            A_length += b * a;
        } else if (tmp < a) {
            A_length += tmp * b;
        } else {
            cout << tmp << " " << a;
        }
        tmp -= c;
    }


    tmp = x;
    while (tmp > 0) {
        if (tmp >= d) {
            tmp -= d;
            B_length += e * d;
        } else if (tmp < d) {
            B_length += tmp * e;
        }
        tmp -= f;
    }

    // cout << A_length << "  " << B_length;
    if (A_length < B_length) {
        cout << "Aoki";
    } else if (A_length > B_length) {
        cout << "Takahashi";
    } else {
        cout << "Draw";
    }
}
