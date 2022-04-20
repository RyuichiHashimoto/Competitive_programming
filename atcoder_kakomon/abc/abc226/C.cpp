#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;

int ctoi(char a) {
    return a - '0';
}

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;
typedef pair<ll, ll> P;

int main() {

    ll n, w;
    cin >> n >> w;


    vector<P> l;
    rep(i, 1, n) {
        ll a, b;
        cin >> a >> b;
        l.push_back(P{a, b});
    }
    sort(l.begin(), l.end(), greater<P>());


    ll ret = 0;
    rep(i, 0, (int)l.size() - 1) {

        int d = min(w, l[i].second);
        // cout << w << " " << l[i].second << " " << d << endl;
        // cout << d << " " << l[i - 1].first << endl;
        ret += l[i].first * d;
        w -= d;
        if (w == 0) {
            break;
        }
    }
    cout << ret << endl;
}