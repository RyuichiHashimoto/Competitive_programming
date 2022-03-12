#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

int main(void) {

    int V, A, B, C;

    cin >> V >> A >> B >> C;

    while (true) {
        if (V < A) {
            cout << "F";
            break;
        }
        V -= A;

        if (V < B) {
            cout << "M";
            break;
        }
        V -= B;

        if (V < C) {
            cout << "T";
            break;
        }
        V -= C;
    }
}