#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

vector<int> V[10000];



int main()
{
   int H,W;
   cin >> H >> W;
   
   int INF = 0x7FFFFF;
   
   vector<string> wall(H);
   rep(i,H) cin >> wall[i];   
   int **dp = new int*[H];
   rep(i,H) dp[i] = new int[W];      
   rep(i,H) fill(dp[i], dp[i]+W,INF);

   dp[0][0] = 1;
   int max_value=1;
   rep(i,H){
      rep(j,W){
         if(i == 0 && j==0){
            continue;
         }
         if (i == 0){
            if (wall[i][j] =='.'){
               dp[i][j] = dp[i][j-1] + 1;
            }
         } else if (j==0){
            if (wall[i][j] =='.'){
               dp[i][j] = dp[i-1][j] + 1;
            }            
         } else {
            if (wall[i][j] == '.'){
               dp[i][j] = min(dp[i-1][j], dp[i][j-1] ) + 1;
            }         
         }

         if (dp[i][j] < INF){
            max_value = max(max_value,dp[i][j]);
         }
         
      }
   }
   cout << max_value;

   
   



   

   rep(i,H) delete dp[i];
   delete dp;
   
}