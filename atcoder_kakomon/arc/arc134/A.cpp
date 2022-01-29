#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int func(int x){
   return x * x + 2 * x + 3;
}

typedef long long ll;

int main()
{
   ll N, L, W;

   cin >> N >> L >> W;

   vector<ll> A(N);

   for (int i = 0;i<N;i++){
      cin >> A[i];
   }
   ll ret =0;

   ll left = 0;
   for (ll a : A)
   {
      if (a > left)
      {
         ret += (a - left + W - 1) / W ;
         left = a + W;
      }
      else
      {
         left = a + W;         
      }
   }
   if (left < L){
      ret += (L - left  + W - 1) / W;
   }

   cout << ret << endl;
}