
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


bool check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    x1 -= x3;
    y1 -= y3;

    x2 -= x3;
    y2 -= y3;

    return x1 * y2 == x2 * y1;
}


int main(void) {

    int N, K;

    cin >> N >> K;

    if (K == 1) {
        cout << "Infinity";
        return 0;
    }

    vector<ll> X(N), Y(N);

    rep(i, 0, N - 1) {
        cin >> X[i] >> Y[i];
    }

    int ret = 0;
    map<ll, int> used;


    rep(i, 0, N - 1) {
        rep(j, i + 1, N - 1) {

            pair<ll, ll> current_p = P{i, j};
            int counter = 0;

            rep(k, 0, N - 1) {
                if ((k == i) or (k == j)) {
                    counter++;
                    continue;
                }

                if (check(X[j], Y[j], X[k], Y[k], X[i], Y[i])) {
                    if (k < current_p.first) {
                        current_p.second = current_p.first;
                        current_p.first = k;
                        // cout << current_p.second << " " << current_p.first << endl;
                    } else if (k < current_p.second) {
                        current_p.second = k;
                    }
                    counter++;
                }
            }

            if (used[current_p.first * 3000 + current_p.second] == 1) {
                continue;
            }

            if (counter >= K) {
                ret++;
                used[current_p.first * 3000 + current_p.second] = 1;
            }
        }
    }
    cout << ret << endl;
}
