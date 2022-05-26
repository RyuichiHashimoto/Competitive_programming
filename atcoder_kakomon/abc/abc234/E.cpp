
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

ll pow(ll x, ll n) {


    ll ret = 1;
    while (n > 0) {
        if (n & 1 == 1) {
            ret = (ret * x);
        }
        x = (x * x);

        n = n >> 1;
    }
    return ret;
}


int main(void) {

    ll X;
    cin >> X;

    vector<ll> tousalist(0);

    rep(i, 1, 9) {
        tousalist.push_back(i);
    }

    rep(i, 0, 9) {
        rep(j, 0, 9) {
            if ((i == 0) && (j == 0)) {
                continue;
            }
            // cout << i << " " << j << endl;
            ll counter = 2;
            ll value = i + j * 10;
            tousalist.push_back(value);
            ll added_val;

            ll last_val = j;
            while (true) {
                added_val = (j - i);
                // cout << added_val + last_val << endl;
                // cout <<
                if ((last_val + added_val <= 9ll) && (last_val + added_val >= 0ll)) {
                    value += (last_val + added_val) * pow(10ll, counter);
                    if (value > 10E17) {
                        break;
                    } else if (value < -1) {
                        break;
                    }
                    if (value == 159) {
                    }
                    tousalist.push_back(value);
                } else {
                    break;
                }
                counter++;
                last_val += j - i;
                if (i == 9) {
                    // cout << j << " " << value << endl;
                }
            }
        }
    }
    sort(tousalist.begin(), tousalist.end());

    cout << *lower_bound(tousalist.begin(), tousalist.end(), X) << endl;


    return 0;
}
