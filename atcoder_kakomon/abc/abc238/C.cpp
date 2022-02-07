#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

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

ll sum_digit(ll x){
   return x*(x+1)/2;
}

ll sum_digit_amari(ll x,ll amari){
   return (x%amari)*((x+1)%amari)/2;
}

ll mod_pow(ll x, ll expo, ll mod)
{
    /*
        return (x  ** expor ) % mod
    */

    ll res = 1;

    while (expo > 0)
    {
        if (expo & 1)
        {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;

        expo = expo >> 1;
    }
    return res;
}


ll amari = 998244353;

int main()
{
   ll a;
   cin >> a;

   string str = to_string(a);
   int counts = str.size();
   ll ans;
   if (counts == 1){
      ans = sum_digit(a);      
   } else {
      ll digit = pow(10,counts-1);
      // cout << (a - digit+1);
      // cout << a -  digit + 1<<endl;
      ans =  sum_digit_amari(a-digit+1,amari) % amari;
      
      for(int i=1;i<counts;i++){    
         ll add =  sum_digit( (9*mod_pow(10,i-1,amari))% amari   );
         ans = (ans + add)%amari;
      }
   }
   cout << ans << endl;  
}