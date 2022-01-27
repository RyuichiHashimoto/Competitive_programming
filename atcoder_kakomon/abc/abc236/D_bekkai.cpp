#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

int N;

const int max_n = 20;
ll mat[max_n][max_n];

vector<pair<int, int>> vec;

bool used[max_n];

int calc(){

   if (vec.size()==N)
   {
      int ret = 0;
      for (auto p: vec){
         ret = ret ^ (mat[p.first][p.second]);
      }
      return ret;
   }

   int l =0;

   while (used[l])
      l++;

   used[l] = true;

   int ret = 0;

   for (int i = l + 1; i < 2 * N;i++){
      if (!used[i]){
         vec.push_back({l, i});
         used[i] = true;
         ret = max(ret, calc());
         vec.pop_back();
         used[i] = false;
      }
   }
   used[l] = false;
   return ret;
}

int main()
{
   cin >> N;

   fill(mat[0], mat[20], 0);
   fill(used, used + max_n, false);

   for (int i = 0; i < 2 * N; i++)
   {
      for (int j = i + 1; j < 2 * N; j++)
      {
         cin >> mat[i][j];
         mat[j][i] = mat[i][j];
      }
   }

   cout << calc()<<endl;
}