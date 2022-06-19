#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;
typedef long long ll;

const int MAX_E = 3001;
typedef pair<int, int> P;

int main() {

    int H, W;
    cin >> H >> W;

    int start_x = -1, start_y = -1;
    int end_x, end_y;

    rep(i, 1, H) {
        string tmp;
        cin >> tmp;

        rep(j, 0, W - 1) {
            if (tmp[j] == 'o') {
                if (start_x == -1) {
                    start_x = i;
                    start_y = j;
                } else {
                    end_x = i;
                    end_y = j;
                }
            }
        }
    }

    cout << abs(end_x - start_x) + abs(start_y - end_y);
}