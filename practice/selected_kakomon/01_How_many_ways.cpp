#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

int main(void) {

    int n, x;

    while (true) {
        cin >> n >> x;
        if (n == 0 && x == 0) {
            return 0;
        }

        int counter = 0;

        rep(i, 1, n - 2) {
            rep(j, i + 1, n - 1) {
                rep(k, j + 1, n) {
                    // cout << i << j << k << end;
                    if (i + j + k == x) {
                        counter++;
                    }
                }
            }
        }
        cout << counter << endl;
    }
}