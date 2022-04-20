
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

    int n, w;
    cin >> n >> w;


    vector<int> W(n), V(n);
    rep(i, 0, n - 1) {
        cin >> V[i] >> W[i];
    }
    int half = n / 2;

    vector<P> before;
    vector<P> after;
    brep(i, half) {
        int tmp = i;
        int counter = 0;
        ll weight = 0, value = 0;
        while (tmp != 0) {
            if (tmp & 1) {
                weight += W[counter];
                value += V[counter];
            }
            tmp >>= 1;
            counter++;
        }
        before.push_back(P{weight, value});
    }
    ll val = -1;

    brep(i, n - half) {
        int tmp = i;
        int counter = 0;
        ll weight = 0, value = 0;
        while (tmp != 0) {
            if (tmp & 1) {
                weight += W[counter + half];
                value += V[counter + half];
            }
            tmp >>= 1;
            counter++;
        }

        after.push_back(P{weight, value});
        if (weight <= w) {
            val = max(val, value);
        }
    }


    sort(after.begin(), after.end());


    int m = 1;
    rep(i, 1, after.size() - 1) {
        if (after[m - 1].second < after[i].second) {
            after[m].first = after[i].first;
            after[m].second = after[i].second;
            m++;
        }
    }
    after.resize(m);

    // reverse(after.begin(), after.end());
    ll ret_val = -1;

    for (auto p : before) {
        if (p.first > w) {
            continue;
        }

        // cout << w - p.first << " ";
        // cout << p.first << " " << p.second << endl;
        P tmp = P{w - p.first, 1};

        auto s = lower_bound(after.begin(), after.end(), tmp);


        if ((*s).first == w - p.first) {
            ret_val = max(ret_val, (*s).second + p.second);
        } else if (s == after.begin()) {
            continue;
        } else {
            s--;
            ret_val = max(ret_val, (*s).second + p.second);
        }
    }

    cout << max(val, ret_val) << endl;

    return 0;
}
