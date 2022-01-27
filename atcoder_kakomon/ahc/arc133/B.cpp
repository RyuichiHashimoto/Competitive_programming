#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int func(int x)
{
   return x * x + 2 * x + 3;
}

int dp[200000];


int dfs(vector<int> &P, vector<int> &Q, int res, int p_pos, int q_pos, int n)
{

   if (n == P.size()){
      return res;
   }

   bool find_flag1 = false;
   int add = 0;

   int qi = 0;
   for (qi = q_pos; qi <= n; qi++)
   {
      if ( Q[qi] % P[n] == 0){
         find_flag1 = true;
         add = max(add, dfs(P, Q, res + 1, n + 1, qi + 1, n + 1));
         break;
      }      
   }

   bool find_flag2 = false;

   int pi;

   if (qi != n)
   {
      for (pi = p_pos; pi <= n; pi++)
      {
         if (Q[n] % P[pi] == 0)
         {
            find_flag2 = true;
            add = max(add, dfs(P, Q, res + 1, pi + 1, n + 1, n + 1));
            break;
         }
      }
   }

   if (!find_flag1 and !find_flag2){
      add = max(add, dfs(P, Q, res, p_pos, q_pos, n + 1));
   }

   return add;
}

struct Data{
   int p, q, val;
};

int main()
{
   int N;
   cin >> N;

   vector<int> P(N);
   vector<int> Q(N);
   vector<int> pos(N + 1);

   rep(i,N){
      cin >> P[i];
   }
   rep(i,N){
      cin >> Q[i];
   }
   
   rep(i,N){
      pos[Q[i]] = i;
   }




}