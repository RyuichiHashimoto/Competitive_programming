#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
using namespace std;
typedef long long ll;
#include <numeric>

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

template <typename T>
T gcd(T x, T y) {
    if (x < y) swap(x, y);
    // xの方が常に大きい
    T r;
    while (y > 0) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

template <typename T>
T lcm(T x, T y) {
    return T(x / gcd(x, y)) * y;
}

ll souwa(ll a) {
    return (a) * (a + 1) / 2;
}

int main() {
    ll N, A, B;

    cin >> N >> A >> B;
    // cout << A << " " << B;
    // cout << lcm(A, B);

    ll A_souwa = souwa(N / A) * A;
    ll B_souwa = souwa(N / B) * B;
    ll saisho = souwa(N / lcm(A, B)) * lcm(A, B);

    cout << souwa(N) - A_souwa - B_souwa + saisho << endl;
}
