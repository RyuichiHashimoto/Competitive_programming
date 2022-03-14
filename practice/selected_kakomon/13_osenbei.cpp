#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

int main(void) {
    int C, R;
    cin >> R >> C;

    vector<vector<int>> zahyo(R + 1);
    rep(i, 1, R) {
        zahyo[i].resize(C + 1);
        rep(j, 1, C) {
            cin >> zahyo[i][j];
        }
    }
    int a = -1;
    brep(i, R) {

        int counter = 0;
        vector<vector<int>> tmp(R + 1);
        rep(j, 1, R) {
            tmp[j].resize(C + 1);
        }
        for (int k = 0; k < R; k++) {
            int offset = 0;
            if ((i >> k) & 1) {
                offset = 1;
            }
            rep(j, 1, C) {
                tmp[k + 1][j] = (zahyo[k + 1][j] + offset) & 1;
            }
        }


        int total = 0;
        rep(j, 1, C) {
            int sum = 0;
            for (int k = 1; k <= R; k++) {
                sum += tmp[k][j];
            }
            sum = max(sum, R - sum);
            total += sum;
        }
        a = max(a, total);
    }
    cout << a << endl;
}