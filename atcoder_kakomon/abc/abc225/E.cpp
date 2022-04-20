#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;

int ctoi(char a) {
    return a - '0';
}

typedef long long ll;
#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)


struct fu {
    ll p, q;
    fu(ll P = 0, ll Q = 1) : p(P), q(Q) {
    }

    bool operator<(const fu &other) const {
        return p * other.q < other.p * q;
    }
    bool operator<=(const fu &other) const {
        return p * other.q <= other.p * q;
    }
    bool operator>(const fu &other) const {
        return p * other.q > other.p * q;
    }
    bool operator>=(const fu &other) const {
        return p * other.q >= other.p * q;
    }
};


int main() {

    int n;

    cin >> n;

    vector<fu> fu_list(n);

    vector<pair<fu, fu>> points(n);
    rep(i, 0, n - 1) {
        ll a, b;
        cin >> a >> b;
        points[i] = make_pair(fu{b, a - 1}, fu{b - 1, a});
    }
    sort(points.begin(), points.end());

    rep(i, 0, n - 1) {
        cout << (double)points[i].first.q / points[i].first.p << endl;
    }

    int counter = 0;
    fu now;

    rep(i, 0, n - 1) {
        if (points[i].second >= now) {
            counter++;
            now = points[i].first;
        }
    }
    cout << counter << endl;
    return 0;
}