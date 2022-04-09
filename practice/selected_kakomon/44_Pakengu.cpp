#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<int, int> P;


int dp1[1000001];
int dp2[1000001];
bool used[1000001];

int main(void) {

    int N;

    vector<int> A(181);

    vector<int> kisuulist;
    rep(i, 1, 180) {
        A[i] = i * (i + 1) * (i + 2) / 6;
        if (A[i] % 2 == 1) {
            kisuulist.push_back(i);
        }
    }

    int _INF = 1E6 + 1;
    fill(dp1, dp1 + 1000001, _INF);
    fill(dp2, dp2 + 1000001, _INF);
    dp1[0] = 0;
    dp2[0] = 0;


    rep(i, 1, 180) {
        rep(j, 0, 1000000) {
            int after = j + A[i];
            if (after > 1000000) {
                continue;
            }
            if (dp1[j] < 5) {
                dp1[after] = min(dp1[j] + 1, dp1[after]);
            }
        }
    }

    for (auto i : kisuulist) {
        rep(j, 0, 1000000) {
            int after = j + A[i];
            if (after > 1000000) {
                continue;
            }

            dp2[after] = min(dp2[j] + 1, dp2[after]);
        }
    }

    while (true) {
        cin >> N;

        if (N == 0) {
            break;
        }
        cout << dp1[N] << " " << dp2[N] << endl;
    }
    // cout << ret << endl;
}
