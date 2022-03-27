#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

int main(void) {

    int A, B, C, D;


    cin >> A >> B >> C >> D;

    if (A < C) {
        cout << "Takahashi" << endl;
    } else if (A > C) {
        cout << "Aoki" << endl;
    } else if (B < D) {
        cout << "Takahashi" << endl;
    } else if (B > D) {
        cout << "Aoki";
    } else {
        cout << "Takahashi" << endl;
    }


    return 0;
}
