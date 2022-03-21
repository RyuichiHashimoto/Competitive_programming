#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<int, int> P;


int main(void) {


    vector<string> f(4), s(4);

    rep(i, 1, 3) {
        cin >> f[i];
    }
    rep(i, 1, 3) {
        cin >> s[i];
    }

    int counter = 0;

    rep(i, 1, 3) {
        if (f[i] != s[i]) {
            counter++;
        }
    }

    if (counter == 0) {
        cout << "Yes";
    } else if (counter == 1) {
        return 1;
    } else if (counter == 2) {
        cout << "No";
    } else if (counter == 3) {
        cout << "Yes";
    }

    return 0;
}
