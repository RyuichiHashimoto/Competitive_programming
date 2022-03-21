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

    int N;
    cin >> N;

    vector<int> s(N);

    rep(i, 1, N) {
        cin >> s[i - 1];
    }


    int max_1 = 0;


    // S[i] = 1;
    int i = 0;
    int counter = 0;
    rep(i, 0, N - 1) {
        if (s[i] == 0) {
            counter = max(0, counter - 1);
        } else {
            counter++;
        }
        max_1 = max(counter, max_1);
    }


    i = 0;
    int max_2 = 0;

    // S[i] = 1;
    counter = 0;
    rep(i, 0, N - 1) {

        if (s[i] == 1) {
            counter = max(0, counter - 1);
        } else {
            counter++;
        }
        max_2 = max(counter, max_2);
    }

    cout << max_1 + max_2 + 1 << endl;
}