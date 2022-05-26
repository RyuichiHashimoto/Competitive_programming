
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

    int N, M, K;

    cin >> N;
    vector<int> T(N);

    rep(i, 1, N) {
        cin >> T[i - 1];
    }

    ll current_value = 0;
    vector<ll> ans(N);
    map<ll, ll> used;
    ll counter = 0;
    ll s;

    vector<ll> prefix(50);

    ll last_value = 1ll << T[0];
    if (N == 1) {
        cout << last_value;
        return 0;
    }

    rep(i, 1, N - 1) {
        ll target_value = 1ll << T[i];
        ll next_value = 1ll << (T[i] + 1);

        ll current = (last_value / target_value + 1) * target_value;

        if (current % next_value == 0) {
            current = (current / target_value + 1) * target_value;
        }
        // cout << current << endl;
        while (true) {
            if (!used[current]) {
                used[current] = true;
                last_value = current;
                break;
            }
            current = (current / target_value + 2) * target_value;
        }
    }

    cout << last_value << endl;

    return 0;
}
