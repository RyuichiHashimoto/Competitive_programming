
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<int, int> P;
const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)


int main(void) {

    int n, from, to;

    vector<ll> kosa(1000002);

    cin >> n;
    rep(i, 1, n) {
        cin >> from >> to;
        kosa[from]++;
        kosa[to + 1]--;
    }

    ll ret = kosa[0];

    rep(i, 1, 1000001) {
        kosa[i] += kosa[i - 1];
        ret = max(ret, kosa[i]);
    }
    cout << ret << endl;
}
