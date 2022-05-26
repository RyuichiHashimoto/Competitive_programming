
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


int main(void) {

    ll N;

    cin >> N;


    ll current = 1;
    ll ret = 0;
    while (true) {
        ll left = current;
        ll right = 1E12 + 1;

        ll current_wari = N / current;
        while (right - left > 1) {
            ll mid = (right + left) / 2;


            ll mid_wari = N / mid;

            if (current_wari == mid_wari) {
                left = mid;
            } else {
                right = mid;
            }
        }

        // cout << "-----------------------" << endl;
        // cout << current << " " << left << endl;
        // cout << N / current << " " << N / (left) << endl;
        ret += (left - current + 1) * (N / left);

        if (left == N) {
            break;
        }
        current = left + 1;
    }
    cout << ret << endl;


    return 0;
}
