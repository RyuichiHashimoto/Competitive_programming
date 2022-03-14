#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1.0E5;

int main(void) {

    string S;
    cin >> S;


    int max_ = -1;
    rep(i, 0, S.size() - 1) {
        int s;
        for (s = i; s < S.size(); s++) {
            char a = S[s];
            if (!(a == 'A' or a == 'C' or a == 'G' or a == 'T')) {
                break;
            }
        }
        max_ = max(max_, s - i);
    }
    cout << max_;
}