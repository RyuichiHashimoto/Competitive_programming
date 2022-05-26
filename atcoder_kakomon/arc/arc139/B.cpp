
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

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define inrange(val, from, to) (from <= val) and (val <= to)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

ll calc_2(ll N, ll A, ll B, ll X, ll Y, ll Z, ll hand) {

    N = N - A * hand;
    if (N < 0) {
        return LL_MAX;
    }
    ll sagyo = (N / B);
    ll rest_sayo = N - sagyo * B;

    return sagyo * Z + rest_sayo * X + Y * hand;
}


ll calc(ll N, ll A, ll B, ll X, ll Y, ll Z) {

    if ((A * X <= Y) && (B * X <= Z)) {
        return N * X;
    } else if ((A * X > Y) && (B * X <= Z)) {
        ll sagyo = (N / A);
        ll rest_sayo = N - sagyo * A;
        return sagyo * Y + rest_sayo * X;
    } else if ((A * X <= Y) && (B * X > Z)) {
        ll sagyo = (N / B);
        ll rest_sayo = N - sagyo * B;
        return sagyo * Z + rest_sayo * X;
    } else {
        if (Y * B < A * Z) {
            return calc(N, B, A, X, Z, Y);
        } else if (Y * B == A * Z) {
            if (A < B) {
                return calc(N, B, A, X, Z, Y);
            }
        }
        ll right = N;
        ll left = 0;

        int counter = 0;
        while (right - left > 1) {
            counter++;
            if (counter == 5000) {
                break;
            }
            ll left_half = left + (right - left) / 3;
            ll right_half = left + (right - left) * 2 / 3;

            ll lv = calc_2(N, A, B, X, Y, Z, left_half);
            ll rv = calc_2(N, A, B, X, Y, Z, right_half);

            if (lv == LL_MAX) {
                right = left_half;
            } else if (rv == LL_MAX) {
                right = right_half;
            } else if (lv > rv) {
                right = right_half;
            } else if (lv < rv) {
                left = left_half;
            } else if (lv == rv) {
                exit(-1);
                // return lv;
            }
        }

        ll left_half = left + (right - left) / 3;
        ll right_half = left + (right - left) * 2 / 3;
        ll one = calc_2(N, A, B, X, Y, Z, left);
        ll two = calc_2(N, A, B, X, Y, Z, right);
        ll three = calc_2(N, A, B, X, Y, Z, right_half);
        ll four = calc_2(N, A, B, X, Y, Z, left_half);


        return min({one, two, three, four});
    }
}


int main(void) {

    int T;
    cin >> T;


    rep(i, 1, T) {
        ll N, A, B, X, Y, Z;

        cin >> N >> A >> B >> X >> Y >> Z;

        cout << calc(N, A, B, X, Y, Z) << endl;
    }
}
