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
    int N,K;

    cin >> N>>K;

    vector<ll> h(N);

    rep(i,N){
        cin >> h[i];
    }
    ll INF = 0x7FFFFFFFFFFFFFFF;

    fill(dp,dp+(N+10),INF);

    dp[0] = 0;

    for(int i = 1;i<N;i++){
        // cout << i <<" ";
        for(int j=max(0,i - K); j <= i-1;j++){
            // cout << j <<" ";
            dp[i] = min(dp[i], dp[j]+abs(h[i]- h[j]));
        }
        // cout << endl;
    }
    cout << dp[N-1];

}