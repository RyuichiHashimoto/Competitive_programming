#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
vector<ll> L[5000];
ll N;
int X;

int dfs(ll pos, ll seki)
{
   if (N == pos){
      if (X == seki)
         return 1;
      else {
         return 0;
      }
   }

   int ret = 0;
   for(ll c: L[pos]){
      if (seki * c > X){
         continue;
      }

      ret += dfs(pos + 1, seki * c);
   }
   
   return ret;
}

int main()
{   
   cin >> N >> X;

   int size = 0;
   rep(i, N)
   {
      cin >> size;
      L[i].resize(size);
      rep(j, size)
      {

         cin >> L[i][j];
      }
   }
   cout << dfs(0, 1) << endl;
}