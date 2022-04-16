
#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<ll, ll> P;
const ll MAX_N = 1.0E5;
// const ll ll_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

typedef pair<ll, ll> P;

vector<int> dp[17];

int main(void) {

    int N;

    cin >> N;
    vector<string> myoji(N), simei(N);

    map<string, int> counter;

    rep(i, 1, N) {
        cin >> myoji[i - 1] >> simei[i - 1];
        counter[myoji[i - 1]]++;
        counter[simei[i - 1]]++;
    }


    rep(i, 1, N) {
        if (counter[myoji[i - 1]] == 1 or counter[simei[i - 1]] == 1) {
        } else {
            if (counter[myoji[i - 1]] == 2 && (simei[i - 1] == myoji[i - 1])) {
                continue;
            }
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}