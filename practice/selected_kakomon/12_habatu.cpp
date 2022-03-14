#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

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
    int N, M;

    cin >> N >> M;


    int x, y;
    int relations[13][13];
    fill(relations[0], relations[13], 0);

    rep(i, 1, M) {
        cin >> x >> y;
        relations[x][y] = 1;
        relations[y][x] = 1;
    }

    int ret = -1;
    brep(i, N) {

        int counter = 0;
        vector<int> cand;
        while ((i >> counter) != 0) {
            if ((i >> counter) & 1) {
                cand.push_back(counter);
            }
            counter++;
        }
        bool ok_flag = true;
        // display((ll)i);
        rep(i, 0, cand.size() - 1) {
            rep(j, i + 1, cand.size() - 1) {
                if (relations[cand[i] + 1][cand[j] + 1] != 1) {
                    ok_flag = false;
                    break;
                }
            }
            if (!ok_flag) {
                break;
            }
        }
        if (ok_flag) {
            ret = max(ret, (int)cand.size());
        }
    }
    cout << ret << endl;
}