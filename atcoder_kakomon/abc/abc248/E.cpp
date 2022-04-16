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


bool issame(double one, double two) {
    return abs(one - two) < 1E-6;
}

bool check(double one, double two, double three) {
    if (issame(one, two + three)) {
        return true;
    } else if (issame(two, one + three)) {
        return true;
    } else if (issame(three, one + two)) {
        return true;
    }
    return false;
}

double calc_distance(ll x1, ll y1, ll x2, ll y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
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
    map<pair<ll, ll>, int> used;


    rep(i, 0, N - 1) {
        rep(j, i + 1, N - 1) {

            pair<ll, ll> current_p = P{i, j};
            if (used[current_p] == 1) {
                continue;
            }
            int counter = 0;


            double distance = calc_distance(X[i], Y[i], X[j], Y[j]);

            rep(k, 0, N - 1) {
                if ((k == i) or (k == j)) {
                    continue;
                }

                double distance_one = calc_distance(X[i], Y[i], X[k], X[k]);
                double distance_two = calc_distance(X[j], Y[j], X[k], X[k]);
                if (check(distance, distance_one, distance_two)) {
                    if (k < current_p.first) {
                        current_p.second = current_p.first;
                        current_p.first = k;

                    } else if (k < current_p.second) {
                        current_p.second = k;
                    }
                    counter++;
                }
            }
            if (used[current_p] == 1) {
                continue;
            }

            if (counter >= K - 2) {
                ret++;
                used[current_p] = 1;
            }
        }
    }
    cout << ret << endl;
}