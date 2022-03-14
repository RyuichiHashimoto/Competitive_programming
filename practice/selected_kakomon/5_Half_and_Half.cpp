#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int MAX_N = 1.0E5;

int main(void) {

    int N;
    string S;
    cin >> N >> S;
    S = S + "abc";

    int counter = 0;
    rep(a, 0, 10) {
        rep(b, 0, 10) {
            rep(c, 0, 10) {
                int ai, bi, ci;
                for (ai = 0; ai < S.size(); ai++) {
                    if (a == S[ai] - '0' || S[ai] == 'a') {
                        break;
                    }
                }

                for (bi = ai + 1; bi < S.size(); bi++) {
                    if (b == S[bi] - '0' || S[bi] == 'b') {
                        break;
                    }
                }

                for (ci = bi + 1; ci < S.size(); ci++) {
                    if (c == S[ci] - '0') {
                        break;
                    }
                }
                if (S.size() != ci || S[ci] == 'c') {
                    counter++;
                }
            }
        }
    }
    cout << counter;
}