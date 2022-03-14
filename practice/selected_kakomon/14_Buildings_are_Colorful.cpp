#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

int main(void) {


    int N, K;
    cin >> N >> K;

    vector<ll> height(N + 1);
    vector<ll> bef_max(N + 1);
    rep(i, 1, N) {
        cin >> height[i];
    }
    ll max_height = -1;
    bef_max[1] = max_height;

    rep(i, 2, N) {
        bef_max[i] = max(bef_max[i - 1], height[i - 1]);
    }

    ll min_money = 0x7FFFFFFFFFFFFFFF;
    brep(i, N) {
        vector<ll> tmp_height(N + 1);
        vector<ll> tmp_bef_max(N + 1);
        rep(j, 1, N) {
            tmp_bef_max[j] = bef_max[j];
        }

        ll money = 0;
        tmp_height[1] = height[1];


        rep(j, 2, N) {
            if ((i >> (j - 1)) & 1) {
                if (height[j] > tmp_bef_max[j]) {
                    tmp_height[j] = height[j];
                } else {
                    tmp_height[j] = tmp_bef_max[j] + 1;

                    rep(k, j + 1, N) {
                        tmp_bef_max[k] = max(tmp_bef_max[k], tmp_height[j]);
                    }

                    // cout < < < < tmp_height[j] << " " << height[j] << endl;
                    money += tmp_height[j] - height[j];
                }
            } else {
                tmp_height[j] = height[j];
            }
        }

        ll max_height = tmp_height[1];
        int counter = 1;
        rep(j, 2, N) {
            if (max_height < tmp_height[j]) {
                max_height = tmp_height[j];
                counter++;
            }
        }
        if (counter >= K) {
            min_money = min(min_money, money);
        }
    }
    cout << min_money << endl;
}