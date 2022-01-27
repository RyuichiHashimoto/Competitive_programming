#include <iostream>
#include <bits/stdc++.h>
#include<map>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

ll mod_pow(ll x, ll expo, ll mod)
{
    /*
        return x %
        expo;

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

int main(void)
{
    ll N, K;

    cin >> N >> K;

    ll result = 1;
    ll amari = 1000000007;

    if (N == 1){
        result =  (K) % amari;
        
    } else if (N==2){        
        result = (K * (K - 1)) % amari;        
    } else {
        
        if (K == 1 || K == 2){
            result = 0;
        } else {
            result = (K * (K - 1)) % amari;
            result = (result * mod_pow(K - 2, N - 2, amari)) % amari;
        }        
    }
    cout << result << endl;
}