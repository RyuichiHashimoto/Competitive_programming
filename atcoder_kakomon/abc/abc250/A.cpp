#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;
typedef long long ll;

const int MAX_E = 3001;


int main() {
    int H, W;
    int R, C;

    cin >> H >> W;

    cin >> R >> C;

    int dy[] = {1, 0, -1, 0};
    int dx[] = {0, 1, 0, -1};

    int counter = 0;
    for (int i = 0; i < 4; i++) {
        int next_x = dx[i] + R;
        int next_y = dy[i] + C;

        if (next_x <= H && next_x >= 1 && next_y <= W && next_y >= 1) {
            counter++;
        }
    }
    cout << counter << endl;
}