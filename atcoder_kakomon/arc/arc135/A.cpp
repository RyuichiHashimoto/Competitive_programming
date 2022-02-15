#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

using namespace std;

#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

const int MAX_N = 1e6;

ll dp[MAX_N + 1]; 

ll amari = 998244353;


ll dfs(ll x){
   if (x < MAX_N && dp[x] != -1){
      return dp[x];
   } 
   if (x == 2 || x ==3){
      return x; 
   }

   ll ret = -1;
   ll seki =1;
   
   if (x %2 == 0){
      ll b = dfs(x/2);
      seki = (b * b) % amari;
   } else {
      ll b = dfs(x/2);
      ll c = dfs(x/2 + 1);
      seki = (b*c)%amari;
   }
   if (x < MAX_N){
      dp[x] = seki;
   }
   

   return seki;
}



int main()
{
   fill(dp, dp+MAX_N,-1);
   queue<ll> que;

   dp[1] = 1;
   dp[2] =2;
   dp[3] = 3;

   ll ret = 1;

   ll X;
   cin >> X;

   ll s = dfs(X);

   cout << s<<endl;
}