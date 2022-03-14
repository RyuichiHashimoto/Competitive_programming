#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;


int main(void) {

    int N = 8, K;

    cin >> K;

    vector<P> queens(K + 1);
    rep(i, 1, K) {
        cin >> queens[i].first >> queens[i].second;
    }
    vector<int> pos(N);
    rep(i, 1, N) {
        pos[i - 1] = i - 1;
    }

    do {

        bool find_flag = true;

        rep(i, 1, K) {
            if (pos[queens[i].first] != queens[i].second) {
                find_flag = false;
                break;
            }
        }
        if (find_flag) {
            bool ok_flag = true;
            rep(i, 0, N - 1) {
                rep(j, i + 1, N - 1) {

                    if ((j - i) == abs(pos[j] - pos[i])) {
                        ok_flag = false;
                    }
                }
            }
            if (ok_flag) {
                break;
            }
        }

    } while (next_permutation(pos.begin(), pos.end()));
    rep(i, 0, N - 1) {
        rep(j, 0, N - 1) {
            if (j == pos[i]) {
                cout << "Q";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}