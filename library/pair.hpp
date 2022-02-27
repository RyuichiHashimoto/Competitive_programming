#include <bits/stdc++.h>

#include <iostream>
#include <map>
using namespace std;

// template <typename T>
// class
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)


/*
    parameter
    ---------
        f_priority: bool
            true:
                ソートの際の第1 要素: first
                ソートの際の第2 要素: second
            false:
                ソートの際の第1 要素: first
                ソートの際の第2 要素: second

        f_greater: bool
            false: 1つ目の要素を昇順 (1, 3, 5, 7)
            true: 1つ目の要素を降順 (7, 5, 3, 1)

        g_greater: bool
            false: 2つ目の要素を昇順 (1, 3, 5, 7)
            true: 2つ目の要素を降順 (7, 5, 3, 1)

    usage
    -----
        vector<P> s;

        pair_greater<P> com;
        com.f_priority = false;
        com.f_greater = true;
        com.s_greater = false;

        sort(s.begin(), s.end(), com);


*/
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

    vector<P> s;

    s.push_back(P{1, 2});
    s.push_back(P{3, 4});
    s.push_back(P{5, 8});
    s.push_back(P{7, 6});
    s.push_back(P{10, 6});

    pair_greater<P> com;
    com.f_priority = false;
    com.f_greater = true;
    com.s_greater = false;


    // com.maximum = true;

    cout << com(s[0], s[1]) << endl;

    // sort(s.begin(), s.end(), greater<P>());
    sort(s.begin(), s.end(), com);

    rep(i, 0, s.size() - 1) {
        cout << s[i].first << " " << s[i].second << endl;
    }
}