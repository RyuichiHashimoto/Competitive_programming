#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
const int N_MAX = 1E5+10;
ll dp[N_MAX];

int main(void)
{
    int N;

    cin >> N;

    vector<ll> h(N);

    rep(i,N){
        cin >> h[i];
    }
    ll INF = 0x7FFFFFFFFFFFFFFF;

    fill(dp,dp+(N+10),INF);

    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for(int i = 2;i<N;i++){
        dp[i] = min(dp[i-1]+ abs(h[i]-h[i-1]),dp[i-2] + abs(h[i] - h[i-2]));
    }
    cout << dp[N-1];

}