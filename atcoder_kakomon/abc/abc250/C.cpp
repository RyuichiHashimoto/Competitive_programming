#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

typedef long long ll;
#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;


const int MAX_E = 3001;


int main() {


    int N, Q;
    cin >> N >> Q;
    vector<int> position(N + 1);
    map<int, int> ma;

    position[0] = -1;
    rep(i, 1, N) {
        position[i] = i;
        ma[i] = i;
    }

    rep(i, 1, Q) {
        int target_val;
        cin >> target_val;

        int pos = ma[target_val];

        if (pos == N) {
            int current_val = position[pos];
            int next_val = position[pos - 1];

            ma[current_val] = pos - 1;
            ma[next_val] = pos;


            swap(position[pos], position[pos - 1]);
        } else {
            int current_val = position[pos];
            int next_val = position[pos + 1];

            ma[current_val] = pos + 1;
            ma[next_val] = pos;

            swap(position[pos], position[pos + 1]);
        }
    }

    rep(i, 1, N) {
        cout << position[i] << " ";
    }
}