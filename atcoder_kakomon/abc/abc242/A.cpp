#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

int main(void) {

    int A, B, C, X;

    cin >> A >> B >> C >> X;


    if (X <= A) {
        cout << "1.000000000000";
    } else if (X <= B) {
        int interval = B - X;
        cout << setprecision(14) << (double)C / (double)(B - A);
    } else {
        cout << "0.000000000000";
    }

    return 0;
}