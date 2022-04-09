
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF / 2ll;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)


int LIS(vector<int> &array) {
    int n = array.size();
    vector<int> dp(array.size());

    int INF = 0x7FFFFFF;


    fill(dp.begin(), dp.end(), INF);
    int max_length = 0;
    rep(i, 0, n - 1) {
        int tmp = array[i];
        if (max_length == 0) {
            dp[0] = tmp;
            max_length++;
        } else if (dp[max_length - 1] < tmp) {
            dp[max_length++] = tmp;
        } else {
            auto s = lower_bound(dp.begin(), dp.begin() + max_length, tmp);
            dp[s - dp.begin()] = tmp;
        }
    }
    return max_length;
}

int main(void) {

    // int dp[];
    int n;
    cin >> n;
    vector<int> array(n);
    rep(i, 1, n) {
        cin >> array[i - 1];
        // cout << n << " " << array[i - 1] << endl;
    }

    cout << LIS(array) << endl;
}
