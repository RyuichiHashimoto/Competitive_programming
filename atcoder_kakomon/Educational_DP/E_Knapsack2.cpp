#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;


struct item{
    ll w, v;
};

int main(void)
{
    int N,W;

    cin >> N >> W;

    vector<item> knap(N+2);

    rep(i,N){
        ll w,v;
        cin >> w>>v;
        knap[i+1] = item{w,v};
    } 

    const int N_MAX = 100;
    const int Profit_MAX = 1E5+3;
    
    //該当価値の中での最小のウェイト
    vector<vector<ll>> dp(N+1);
    
    ll INF_MAX = 0xFFFFFFFFF;

    rep(i,N+1){        
        dp[i].resize(Profit_MAX+1);
        fill(dp[i].begin(),dp[i].end(),INF_MAX);
    }    
    dp[0][0] = 0;    
    ll max_val = -1;

    for(int i=1;i<=N;i++){
        for(int p=0; p <= Profit_MAX; p++){ 
            if ( p - knap[i].v < 0 ){
                dp[i][p] = dp[i-1][p];
            } else {
                dp[i][p] = min(dp[i-1][p],dp[i-1][ p - knap[i].v ] + knap[i].w); 
                
                if (dp[i][p] <= W){
                    max_val = max((ll)p,max_val);                    
                }
            }        
        }
    }

    cout << max_val<<endl;   
}