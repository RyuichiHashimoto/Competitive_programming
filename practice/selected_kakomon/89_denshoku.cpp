
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<ll, ll> P;
const ll MAX_N = 1.0E5;
// const ll ll_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

/* compress
    X を座標圧縮して書き換える（副作用）
    返り値: ソート済みの値
    計算量: O(n log n)

    URL: https://algo-logic.info/coordinate-compress/
*/
template <typename T>
vector<pair<T, int>> compress(vector<T> &X) {

    vector<pair<T, int>> ret;

    T before = X[0];
    int counter = 1;

    rep(i, 1, X.size() - 1) {
        if (before != X[i]) {
            ret.push_back(pair{before, counter});
            before = X[i];
            counter = 1;
        } else {
            counter++;
        }
    }
    ret.push_back(pair{before, counter});

    return ret;
}
typedef pair<int, int> P;

int main(void) {

    int n;

    cin >> n;

    vector<int> A(n);
    rep(i, 1, n) {
        cin >> A[i - 1];
    }


    vector<int> gizzaku;
    int last_val = -1;
    int idx_ = 0;
    rep(i, 0, n) {
        if (last_val != A[i]) {
            idx_++;
            last_val = A[i];
        } else {
            gizzaku.push_back(idx_);
            idx_ = 1;
            last_val = A[i];
        }
    }
    gizzaku.push_back(idx_ - 1);


    int ret = 0;
    if (gizzaku.size() == 1) {
        cout << n << endl;
    } else if (gizzaku.size() == 2) {
        cout << n << endl;
    } else {
        rep(i, 1, gizzaku.size() - 2) {
            ret = max(ret, gizzaku[i - 1] + gizzaku[i] + gizzaku[i + 1]);
        }
        cout << ret << endl;
    }


    return 0;
}
