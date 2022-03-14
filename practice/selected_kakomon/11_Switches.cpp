#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

typedef pair<int, int> P;


int main(void) {

    int N, M;

    cin >> N >> M;


    int X[11][11];
    int P[11];
    int V[11];
    fill(X[0], X[11], 0);
    fill(P, P + 11, 0);

    rep(i, 1, M) {
        int k = 0;
        cin >> k;
        rep(j, 1, k) {
            int tmp;
            cin >> tmp;
            X[i][tmp] = 1;
        }
    }
    rep(i, 1, M) {
        cin >> P[i];
    }

    // cout << "-----------------" << endl;

    int ret = 0;
    for (int i = 0; i < (1 << N); i++) {
        int counter = 0;
        fill(V, V + 11, 0);
        while ((i >> counter) != 0) {
            if ((i >> counter) & 1) {
                rep(k, 1, 10) {
                    V[k] += X[k][counter + 1];
                }
            }
            counter++;
        }

        counter = 0;

        rep(j, 1, M) {
            if ((V[j] % 2) == P[j]) {
                counter++;
            }
        }
        if (counter == M) {
            ret++;
        }
    }
    cout << ret << endl;
}