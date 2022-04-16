
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
    int N;

    cin >> N;
    vector<int> ruisekiwa(N);

    map<int, vector<int>> survery;
    rep(i, 1, N) {
        cin >> ruisekiwa[i - 1];
        survery[ruisekiwa[i - 1]].push_back(i);
    }

    int Q;
    cin >> Q;

    rep(i, 1, Q) {
        int from, to, L;

        cin >> from >> to >> L;

        auto li = lower_bound(survery[L].begin(), survery[L].end(), from);
        auto ui = lower_bound(survery[L].begin(), survery[L].end(), to + 1);

        if (li == survery[L].end()) {
            cout << 0 << endl;
            continue;
        }

        cout << ui - li << endl;
    }
}
