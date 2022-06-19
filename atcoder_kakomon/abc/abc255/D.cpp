#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
using namespace std;
typedef long long ll;
#include <numeric>

const int MAX_E = 3001;

ll kaijou(ll a, ll mod) {

    ll ret = 1;
    rep(i, 1, a) {
        ret = (ret * i);
    }
    return ret;
};


int divisor(ll number, ll upper_limit) {
    /*
        数字 numberの約数を小さい順に列挙
        計算量: sqrt(number);

    */
    int ret = 0;

    ll val = number / upper_limit;

    for (ll i = val; i <= upper_limit; i++) {
        if (i == 0) {
            continue;
        }

        if (number % i == 0) {
            if (i * i == number) {
                if (i <= upper_limit) {
                    ret++;
                }
            } else {
                if ((i <= upper_limit) && (number / i <= upper_limit)) {
                    ret = ret + 2;
                }
            }
        }
    }
    return ret;
}

int main() {

    int N, Q;
    cin >> N >> Q;

    vector<ll> val_list(N);
    vector<ll> ruiseki(N);

    rep(i, 1, N) {
        cin >> val_list[i - 1];
    }

    sort(val_list.begin(), val_list.end());

    ruiseki[0] = val_list[0];
    rep(i, 1, N - 1) {
        ruiseki[i] = ruiseki[i - 1] + val_list[i];
    }

    rep(i, 1, Q) {
        ll a;
        cin >> a;
        auto c = lower_bound(val_list.begin(), val_list.end(), a);

        int idx = c - val_list.begin();

        if (idx == 0) {
            cout << abs(ruiseki[N - 1] - N * a) << endl;
        } else {
            ll bef_count = idx - 1;
            ll bef_sum = abs(ruiseki[bef_count] - (bef_count + 1) * a);
            // cout << ruiseki[bef_count] << " " << (bef_count + 1) * a << endl;

            ll aft_count = N - idx;

            ll aft_sum = abs(ruiseki[N - 1] - ruiseki[bef_count] - aft_count * a);

            // cout << bef_sum << " " << aft_sum << endl;
            cout << aft_sum + bef_sum << endl;
        }
        // break;
    }
}
