
#include <bits/stdc++.h>

#include <cmath>
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

typedef pair<ll, ll> P;

vector<int> dp[17];


int main(void) {

    int Q;

    cin >> Q;

    deque<P> que;

    vector<ll> que1a, que1b, que2;

    rep(i, 1, Q) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            ll a, b;
            cin >> a >> b;
            que.push_back(P(a, b));
        } else {
            ll c;
            cin >> c;
            que2.push_back(c);
        }
    }

    for (auto c : que2) {

        vector<P> target_list;
        ll size = 0;

        while (true) {

            P p = que.front();
            que.pop_front();
            if (p.second == c) {
                target_list.push_back(p);
                break;
            } else if (p.second < c) {
                target_list.push_back(p);
                c = c - p.second;

            } else {
                P added = P{p.first, c};
                P rest = P{p.first, p.second - c};
                // cout << c - p.second << endl;
                // cout << added.first << " " << added.second << endl;
                target_list.push_back(added);
                // cout << p.
                // cout << rest.first << " " << rest.second << endl;
                que.push_front(rest);
                break;
            }
        }

        ll ret = 0;
        for (auto s : target_list) {
            ret += s.first * s.second;
        }
        cout << ret << endl;
    }


    return 0;
}