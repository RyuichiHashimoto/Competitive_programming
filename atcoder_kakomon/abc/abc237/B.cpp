#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

int main()
{
   int H, W;
   cin >> H >> W;

   vector<vector<ll>> matrix(H);

   rep(i,H){
      matrix[i].resize(W);
      rep(j,W){
         cin >> matrix[i][j];
      }
   }
   rep(i,W){
      rep(j,H){
         cout << matrix[j][i] << " ";
      }
      cout << endl;
   }
}