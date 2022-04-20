#include <bits/stdc++.h>

#include <iostream>
#include <set>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;
struct query {
    ll a, x, k;
};

ll pow_(ll x, ll n) {

    ll ret = 1;
    while (n > 0) {
        if (n & 1 == 1) {
            ret = (ret * x);
        }
        x = (x * x);

        n = n >> 1;
    }
    return ret;
}

void display(ll x) {

    int bit[64];
    fill(bit, bit + 64, 0);

    int counter = 0;
    while (x != 0) {
        bit[counter++] = (int)(x & 1);
        x = x >> 1;
    }
    reverse(bit, bit + 64);
    for (int i = 0; i < 64; i++) {
        cout << bit[i];
    }
    cout << endl;
}


int main(void) {

    string S;
    int Q;
    cin >> S >> Q;


    vector<pair<int, pair<int, int>>> query(Q);
    rep(i, 1, Q) {
        ll a, b;
        cin >> a >> b;

        pair<int, pair<int, int>> q(i - 1, pair<int, int>{a, b});
        query[i - 1] = q;
    }
}