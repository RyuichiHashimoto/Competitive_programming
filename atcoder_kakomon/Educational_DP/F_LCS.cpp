#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define rep(i,from, to) for (int i = (int)from; i <= (int)(to); i++)


const int MAX_E = 3001;
int dp[MAX_E][MAX_E];

int main(void)
{
    string s,t;
    cin >> s >> t;
    fill(dp[0],dp[MAX_E],0);
        
    rep(i,1,s.size()){
        rep(j,1,t.size()){
            if (s[i-1]==t[j-1]){                
                dp[i][j] = dp[i-1][j-1]+ 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }    
        }
    }
    int len = dp[s.size()][t.size()];
    if (len == 0){
        return 0;
    }
 
    int i = s.size();
    int j = t.size();
    char *ans = new char[len];

    while (len>0){
        if (s[i-1] == t[j-1]){            
            ans[len-1] = s[i-1];
            i--;
            j--;
            len--;
        } else if (dp[i][j]==dp[i-1][j]){
            i--;
        } else{
            j--;
        }
    }
    rep(i,0,dp[s.size()][t.size()]-1){
        cout << ans[i];
    }

    delete ans;


    return 0;
}