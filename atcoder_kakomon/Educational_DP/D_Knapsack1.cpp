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
    const int W_MAX = 1E5;
    vector<vector<ll>> dp(N+1);
    rep(i,N+1){
        dp[i].resize(W+1);
        fill(dp[i].begin(),dp[i].end(),-1);
    }    
    fill(dp[0].begin(),dp[0].end(),0);


    ll max_val = -1;
    for(int i=1;i<=N;i++){
        for(int j=1; j <= W; j++){
            dp[i][j] = dp[i-1][j];
            if (j - knap[i].w >= 0){
                if (dp[i-1][j - knap[i].w] !=-1){

                    dp[i][j] = max(dp[i][j],dp[i-1][j - knap[i].w] +  knap[i].v);  
                    max_val = max(dp[i][j],max_val);
                }
            }
        }
    }

    cout <<max_val;
 
    


}