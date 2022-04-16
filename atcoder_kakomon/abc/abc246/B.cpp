#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<int, int> P;

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

int main(void) {

    ll a, b;

    cin >> a >> b;

    double distance = sqrt(a * a + b * b);

    cout << setprecision(10) << a / distance << " " << b / distance << endl;
}
