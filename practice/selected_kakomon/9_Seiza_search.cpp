#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

typedef pair<int, int> P;

template <typename T>
struct pair_greater {
    bool f_greater = false;
    bool s_greater = false;
    bool f_priority = true;

    constexpr bool operator()(const T &x, const T &y) const {
        if (f_priority) {
            if (x.first != y.first) {
                return (f_greater) == (x.first > y.first);
            } else {
                return (s_greater) == (x.second > y.second);
            }
        } else {
            if (x.second != y.second) {
                return (s_greater) == (x.second > y.second);
            } else {
                return (f_greater) == (x.first > y.first);
            }
        }
    };
};


int main(void) {

    int m, n;
    cin >> m;

    vector<P> base;

    pair_greater<P> com;
    com.f_priority = false;
    com.f_greater = false;
    com.s_greater = false;


    rep(i, 0, m - 1) {
        int x, y;
        cin >> x >> y;
        base.push_back(P{x, y});
    }

    cin >> n;
    vector<P> zahyo;
    map<int, map<int, int>> zahyo_map;
    rep(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        zahyo_map[x][y] = 1;
        zahyo.push_back(P{x, y});
    }

    sort(zahyo.begin(), zahyo.end(), com);


    rep(i, 0, n - 1) {
        int base_x, base_y;
        base_x = zahyo[i].first;
        base_y = zahyo[i].second;


        int j;
        for (j = 1; j < m; j++) {
            int x = base_x + (base[j].first - base[0].first);
            int y = base_y + (base[j].second - base[0].second);
            if (!zahyo_map[x][y]) {
                break;
            }
        }
        // cout << j << endl;
        if (j == m) {
            cout << base_x - base[0].first << " " << base_y - base[0].second << endl;
            return 0;
        }
    }
}