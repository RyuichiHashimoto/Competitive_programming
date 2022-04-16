#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll n = s.size();
    vector<ll> cnt(n + 1);  //累積和
    for (ll i = 0; i <= n - 1; i++) {
        if (s[i] == '.')
            cnt[i + 1] = cnt[i] + 1;
        else
            cnt[i + 1] = cnt[i];
    }  // cnt[r] - cnt[l] で s[l,r) の '.' の数を表す
    ll ans = 0;
    ll r = 0;
    for (ll l = 0; l <= n - 1; l++) {
        while (r <= n - 1 && cnt[r + 1] - cnt[l] <= k) {
            r = r + 1;
        }
        ans = max(ans, r - l);
    }
    cout << ans << endl;
    return 0;
}