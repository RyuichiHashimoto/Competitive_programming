#include <bits/stdc++.h>

#include <iostream>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

int main(void) {
    ll H;

    cin >> H;
    cout << setprecision(10) << sqrt(H * (H + 12800000));
}