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

    int x1, x2, x3, x4;
    int y1, y2, y3, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (x1 == x3) {
        x4 = x2;
    } else if (x1 == x2) {
        x4 = x3;
    } else if (x2 == x3) {
        x4 = x1;
    }

    if (y1 == y3) {
        y4 = y2;
    } else if (y1 == y2) {
        y4 = y3;
    } else if (y2 == y3) {
        y4 = y1;
    }

    cout << x4 << " " << y4 << endl;
}
