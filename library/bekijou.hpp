#include <iostream>
using namespace std;
#include <limits.h>
#include <queue>

typedef long long ll;

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

ll pow(ll x , ll n){
    
    
    ll ret = 1;
    while (n> 0){
        if (n &1 == 1){
            ret = (ret * x) ;
        }
        x = (x * x);

        n = n >> 1;        
    }
    return ret;
}
int main(void)
{
    cout << pow(10, 5);
}