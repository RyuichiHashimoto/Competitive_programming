#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
const int N_MAX = 1E5+10;
ll dp[N_MAX][3];

struct candidate{
    ll a,b,c;
};

int main(void)
{
    int N;
    cin >> N;

    vector<candidate> sentakusi(N+1);

    rep(i,N){
        ll a,b,c;
        cin >> a >> b >> c;
        sentakusi[i+1] = candidate{a,b,c};        
    }
    fill(dp[0],dp[N+1],0x8000000000000000);

    dp[0][0] =0;
    dp[0][1] =0;
    dp[0][2] =0;

    rep(i,N){
        dp[i+1][0] = max(dp[i][1],dp[i][2]) + sentakusi[i+1].a;
        dp[i+1][1] = max(dp[i][2],dp[i][0]) + sentakusi[i+1].b;
        dp[i+1][2] = max(dp[i][0],dp[i][1]) + sentakusi[i+1].c;
    }
    rep(i,N){
        // cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2]<<endl;
    }
    cout << max({dp[N][0],dp[N][1],dp[N][2]});
    



}