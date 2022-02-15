
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int MAX_N = 1<<20;

typedef long long ll;

ll mod_pow(ll x, ll expo, ll mod)
{
    /*
        return (x  ** expor ) % mod
    */

    ll res = 1;
    x = x%mod;

    while (expo > 0)
    {
        if (expo & 1)
        {
            res = (res * (x)) % mod;
        }
        x = (x * x) % mod;

        expo = expo >> 1;
    }
    return res;
}
int main()
{
   ll N,K,M;
   cin >> N >> K >> M;
   ll amari =  998244353;

   if (M%amari == 0){
      cout <<0<<endl;
   }else {
      ll r = mod_pow(K,N,amari-1);
      cout << mod_pow(M,r,amari)<<endl;
   }


}