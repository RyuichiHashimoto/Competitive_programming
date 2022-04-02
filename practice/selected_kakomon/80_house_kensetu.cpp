
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

typedef pair<ll, ll> P;

template <typename T>
vector<vector<T>> accumlates_2d(vector<vector<T>> &info) {
    /*
        第１列及び第1行は必ず0ベクトルであることが前提

    */
    vector<vector<T>> ret(info.size(), vector<T>(info[0].size(), 0));
    int H = info.size() - 1;
    int W = info[0].size() - 1;
    // cerr << " : " << H << " " << W;

    rep(i, 1, H) {
        rep(j, 1, W) {
            ret[i][j] = ret[i - 1][j] + ret[i][j - 1] - ret[i - 1][j - 1] + info[i][j];
        }
    }
    return ret;
}

template <typename T>
T culmulativesum_2d(vector<vector<T>> &s, int from_x, int from_y, int to_x, int to_y) {
    /*
        第１列及び第1行は必ず0ベクトルであることが前提
    */
    return s[to_x][to_y] - s[from_x - 1][to_y] - s[to_x][from_y - 1] + s[from_x - 1][from_y - 1];
}


int main(void) {

    ll H, W, K, V;

    cin >> H >> W >> K >> V;

    vector<vector<ll>> toti(H + 1, vector<ll>(W + 1, 0));


    rep(i, 1, H) {
        rep(j, 1, W) {
            cin >> toti[i][j];
        }
    }
    vector<vector<ll>> ruiseki = accumlates_2d(toti);
    ll min_ = 0;
    rep(from_x, 1, H) {
        rep(from_y, 1, W) {
            rep(to_x, from_x, H) {
                rep(to_y, from_y, W) {
                    ll price = (to_x - from_x + 1) * (to_y - from_y + 1) * K;
                    ll a = culmulativesum_2d(ruiseki, from_x, from_y, to_x, to_y);
                    if (V >= price + a) {
                        min_ = max(min_, (to_x - from_x + 1) * (to_y - from_y + 1));
                    }
                }
            }
        }
    }
    cout << min_ << endl;
}
