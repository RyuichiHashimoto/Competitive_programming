#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;


int main(void) {

    int N;
    cin >> N;
    vector<int> perm(N);
    vector<int> P(N), Q(N);

    rep(i, 0, N - 1) {
        cin >> P[i];
    }
    rep(i, 0, N - 1) {
        cin >> Q[i];
    }
    rep(i, 0, N - 1) {
        perm[i] = i;
    }


    int p = -1, q = -1;
    int count = 1;
    do {
        bool match_P = true;

        rep(i, 0, N - 1) {
            if (P[i] != (perm[i] + 1)) {
                match_P = false;
                break;
            }
        }
        if (match_P) {
            p = count;
        }

        bool match_Q = true;

        rep(i, 0, N - 1) {
            if (Q[i] != (1 + perm[i])) {
                match_Q = false;
                break;
            }
        }
        if (match_Q) {
            q = count;
        }
        if (p != -1 && q != -1) {
            break;
        }
        count++;

    } while (next_permutation(perm.begin(), perm.end()));

    // cout << count << " " << p << " " << q << endl;
    cout << abs(p - q);
}