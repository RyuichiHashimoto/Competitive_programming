
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

    vector<int> V(n);

    rep(i, 1, n) {
        cin >> V[i - 1];
    }

    vector<P> com = compress(V);
    stack<P> sta;
    int idx_ = 0;
    for (int i = 0; i < (int)com.size(); i++) {
        // cout << idx_ + 1 << " " << endl;
        if (!sta.empty()) {
            // cout << idx_ + 1 << " " << sta.top().first << " " << sta.top().second << endl;
        }

        if (sta.empty()) {
            sta.push(com[i]);
        } else {
            P s = sta.top();

            if (((idx_ + 1) % 2) == 0) {
                sta.pop();

                if (sta.empty()) {
                    sta.push(P{com[i].first, s.second + com[i].second});
                } else {
                    P tmp = sta.top();
                    sta.pop();
                    sta.push(P{com[i].first, s.second + com[i].second + tmp.second});
                }
            } else {
                sta.push(com[i]);
            }
        }


        // if (idx_ == 1) {
        //     int ret = 0;
        //     while (!sta.empty()) {
        //         pair<int, int> P = sta.top();
        //         sta.pop();
        //         if (P.first == 0) {
        //             cout << P.first << " " << P.second << endl;
        //             ret += P.second;
        //         } else {
        //             cout << P.first << " " << P.second << endl;
        //         }
        //     }
        //     cout << ret << endl;
        //     return 1;
        //     break;
        // }

        idx_ += com[i].second;
    }
    int ret = 0;
    while (!sta.empty()) {
        pair<int, int> P = sta.top();
        sta.pop();
        if (P.first == 0) {
            // cout << P.first << " " << P.second << endl;
            ret += P.second;
        } else {
            // cout << P.first << " " << P.second << endl;
            // cout << "asd";
        }
    }
    cout << ret << endl;
    // for (auto s : sta) {
    // }
    // cout << shiro_count << endl;
    return 0;
}
