#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

int main(void) {

    int a, b;

    cin >> a >> b;

    if (abs(a - b) == 1) {
        cout << "Yes";
    } else if (abs(a - b) == 9) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}