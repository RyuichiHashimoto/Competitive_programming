#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define rep(i,from, to) for (int i = (int)from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_E = 3001;
double dp[MAX_E][MAX_E];

int main(void)
{
    

    int N;
    cin >> N;

    vector<double> prob(N+1);
    rep(i,1,N){
        cin >> prob[i];
    }
    fill(dp[0],dp[3001],0);
    
    dp[1][0] = 1 - prob[1];
    dp[1][1] = prob[1];

    rep(i,2,N){
        rep(j,0,i){
            if (j == 0){
                dp[i][j] = dp[i-1][j]*(1-prob[i]);
            } else {
                dp[i][j] = dp[i-1][j-1] * prob[i] + dp[i-1][j] * (1-prob[i]); 
            }
        }
    }
    rep(i,1,N){
        rep(j,0,N){
            // cout.width(6);
            // cout << std::setprecision(4) << dp[i][j] << " ";
        }
        // cout << endl;
    }
    double probability = 0;

    rep(i,(int)N/2+1,N){
        probability = probability + dp[N][i];
    }    
    cout <<std::setprecision(10) << probability<<endl;
}