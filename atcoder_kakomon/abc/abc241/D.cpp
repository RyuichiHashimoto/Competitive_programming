#include <bits/stdc++.h>

#include <iostream>
#include <set>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;
struct query {
    ll a, x, k;
};

int main(void) {

    int Q;
    cin >> Q;

    ll a, b, c;

    multiset<ll> ma;


    rep(i, 1, Q) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            ma.insert(b);
            // cout << "array: ";
            // for (auto s :e ma) {
            // cout << s << " ";
            // }
            // cout << endl;

        } else if (a == 2) {
            cin >> b >> c;
            // continue;
            auto s = ma.upper_bound(b);

            if (s == ma.begin()) {
                cout << "-1" << endl;
                continue;
            }

            s--;

            bool not_found_flag = false;

            rep(j, 2, c) {
                if (s == ma.begin()) {
                    not_found_flag = true;
                    break;
                }
                s--;
            }

            if (!not_found_flag) {
                cout << *s << endl;
            } else {
                cout << "-1" << endl;
            }

        } else if (a == 3) {
            cin >> b >> c;
            // continue;

            auto s = ma.lower_bound(b);
            if (s == ma.end()) {
                cout << "-1" << endl;
                continue;
            }
            // cout << *s << endl;


            bool not_found_flag = false;
            rep(j, 2, c) {
                s++;
                if (s == ma.end()) {
                    not_found_flag = true;
                    break;
                }
            }

            if (not_found_flag) {
                cout << "-1" << endl;
            } else {
                cout << *s << endl;
            }
        }
    }
}