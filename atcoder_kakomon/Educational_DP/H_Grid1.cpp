#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define rep(i,from, to) for (int i = (int)from; i <= (int)(to); i++)

typedef long long ll;



int main(void)
{
    int H,W;
    cin >> H>>W;

    vector<string> meikyu(H+1);

    rep(i,1,H){
        cin >> meikyu[i];
        meikyu[i] = "1"+meikyu[i];
    }
    ll amari = 1E9 + 7;
    ll dp[1001][1001];
    fill(dp[0],dp[1001],0);

    dp[1][1]=1;

    rep(i,1,H){
        rep(j,1,W){
            if (meikyu[i][j] == '#'){
                dp[i][j] = 0ll;
            } else {                
                if (i == 1 & j == 1){
                    continue;
                }
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) %(amari);
            }
        }
    }
    rep(i,1,H){
        rep(j,1,W){
            // cout << dp[i][j]<<" ";
        }
        // cout << endl;
    }
    cout << dp[H][W]<<endl;



}