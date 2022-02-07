#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

ll pow(ll x, ll n)
{

   ll ret = 1;
   while (n > 0)
   {
      if (n & 1 == 1)
      {
         ret = (ret * x);
      }
      x = (x * x);

      n = n >> 1;
   }
   return ret;
}

int main()
{
   ll a;
   cin >> a;

   ll lower = pow(-2, 31);
   ll upper = pow(2, 31);

   if (a >= lower && a < upper){
      cout << "Yes";
   }else {
      cout << "No";
   }
}