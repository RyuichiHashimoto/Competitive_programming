
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

    int N;
    cin >> N;
    int INF = 0x7FFFFFF;
    vector<int> dp(N, INF);


    vector<int> a(N);

    int max_length = 0;


    rep(i, 1, N) {
        int tmp;
        cin >> tmp;
        tmp *= -1;
        // cout << "----'''''''''''''''''''''''''-----" << endl;
        // cout << "first" << endl;
        if (max_length == 0) {
            dp[0] = tmp;
            max_length++;
        } else if (dp[max_length - 1] <= tmp) {
            dp[max_length++] = tmp;
        } else {
            auto s = upper_bound(dp.begin(), dp.end() + max_length, tmp);

            // cout << "pointer::" << s - dp.begin() << endl;
            if (true) {
                // cout << "append:" << s - dp.begin() << " " << *s << endl;
                dp[s - dp.begin()] = tmp;
                // max_length++;
            } else {
                // cout << "ins:" << s - dp.begin() << " " << *s << endl;
                dp[s - dp.begin()] = tmp;
            }
        }
        // cout << "---------" << endl;
        // rep(i, 0, max_length - 1) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
    }


    cout << max_length << endl;
}
