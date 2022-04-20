
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

typedef pair<ll, ll> P;

int main(void) {

    ll N, K, L, R;
    cin >> N >> K >> L >> R;

    vector<ll> A(N);
    vector<ll> vec_before(N / 2);
    vector<ll> vec_after(N - N / 2);
    rep(i, 0, N - 1) {
        cin >> A[i];
    }


    rep(i, 0, N / 2 - 1) {
        vec_before[i] = A[i];
    }
    rep(i, N / 2, N - 1) {
        vec_after[i - N / 2] = A[i];
    }


    vector<vector<ll>> before(21, vector<ll>(0));
    vector<vector<ll>> after(21, vector<ll>(0));

    brep(i, vec_before.size()) {
        ll let = 0;
        ll tmp = i;
        ll counter = 0;
        while (tmp != 0) {

            if (tmp & 1) {
                let += vec_before[counter];
            }
            counter++;
            tmp >>= 1;
        }

        before[__builtin_popcount(i)].push_back(let);
    }

    brep(i, vec_after.size()) {
        ll let = 0;
        ll tmp = i;
        ll counter = 0;
        while (tmp != 0) {

            if (tmp & 1) {
                let += vec_after[counter];
            }
            counter++;
            tmp >>= 1;
        }
        after[__builtin_popcount(i)].push_back(let);
    }


    rep(i, 1, 20) {
        if (before[i].size() != 0) {
            sort(before[i].begin(), before[i].end());
        }
        if (after[i].size() != 0) {
            sort(after[i].begin(), after[i].end());
        }
    }
    // cout << "asd";
    // return 1;


    ll ret = 0;
    rep(i, 0, K) {
        ll bef_count = i;
        ll after_count = K - i;
        if (after_count > 20 or bef_count > 20) {
            continue;
        }

        for (auto s : before[bef_count]) {
            if (s > R) {
                continue;
            }
            auto pos = lower_bound(after[after_count].begin(), after[after_count].end(), L - s);
            auto pos_1 = lower_bound(after[after_count].begin(), after[after_count].end(), R - s + 1);
            ret += (ll)(pos_1 - pos);
        }
    }
    cout << ret << endl;
}
