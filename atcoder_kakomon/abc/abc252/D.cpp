#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

using namespace std;
typedef long long ll;

const int MAX_E = 3001;

ll kaijou(ll a, ll mod) {

    ll ret = 1;
    rep(i, 1, a) {
        ret = (ret * i);
    }
    return ret;
};

ll kaijou_list[200001];

ll nCk(int n, int k) {
    ll x = 1;  // n!の初期値
    ll y = 1;  // (n-k)!の初期値
    ll z = 1;  // k!の初期値

    rep(i, 0, n - 1) x *= n - i;          // n!を計算
    rep(i, 0, n - k - 1) y *= n - k - i;  // (n-k)!を計算
    rep(i, 0, k - 1) z *= k - i;          // k!を計算

    return (x / (y * z));  // 定義通りに計算
}

int main() {
    int N;
    cin >> N;


    int used[20];
    fill(used, used + 20, 0);
    int counter = 0;
    rep(i, 1, N) {
        int a;
        cin >> a;
        used[a]++;
    }
    rep(i, 0, 20) {
        cout << i << " " << used[i] << endl;
    }
    cout << "-----------------" << endl;

    int bai = 1;

    for (int i = 0; i < 20; i++) {
        if (used[i] != 0) {
            bai *= kaijou((ll)used[i], -1);
            counter++;
        } else if (used[i] == 1) {
        }
    }
    cout << bai << endl;

    cout << counter * (counter - 1) * (counter - 2) << endl;
}
