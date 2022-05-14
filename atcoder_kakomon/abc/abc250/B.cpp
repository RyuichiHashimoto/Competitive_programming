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
    int N, A, B;

    cin >> N >> A >> B;


    for (int i = 0; i < N; i++) {
        rep(j, 1, A) {
            string g = "";

            rep(a, 1, N) {
                if ((i + a) % 2 == 1) {
                    g = g + string(B, '.');
                } else {
                    g = g + string(B, '#');
                }
            }
            cout << g << endl;
        }
    }
    return 0;
}