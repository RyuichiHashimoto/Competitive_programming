#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

namespace prime_number
{

    typedef long long ll;
    typedef pair<long, long> P;
    const int MAX_N = 400000;

    bool is_prime(ll number)
    {
        /*
            numberが素数か判定する。


            True: 引数 numberが素数
            False: 引数 numberが素数ではない
            計算量: sqrt(number)
        */
        for (ll i = 2; i * i <= number; i++)
        {
            if (number % i == 0)
                return false;
        }
        return number != 1;
    }

    vector<ll> divisor(ll number)
    {
        /*
            数字 numberの約数を小さい順に列挙                    
            計算量: sqrt(number);

        */
        vector<ll> res;

        for (int i = 1; i * i <= number; i++)
        {

            if (number % i == 0)
            {
                res.push_back(i);
                if (i * i == number)
                {
                    res.push_back(number / i);
                }
            }
        }
        return res;
    }

    vector<P> prime_factor_as_vect(ll number)
    {

        vector<P> ret;
        for (ll i = 2; i * i < number; i++)
        {
            ll count = 0;
            while (number % i == 0)
            {
                count++;
                number = number / i;
            }
            if (count != 0)
                ret.push_back(P(i, count));
        }
        if (number != 1)
            ret.push_back(P(number, 1));

        return ret;
    }

    map<ll, ll> prime_factor_as_map(ll number)
    {
        map<ll, ll> ret;

        for (ll i = 2; i * i < number; i++)
        {
            ll count = 0;
            while (number % i == 0)
            {
                count++;
                number = number / i;
            }
            ret[i] = count;
        }

        if (number != 1)
            ret[number] = 1;

        return ret;
    }
}

int main(void)
{
    ll K;
    cin >> K;
    ll counter=0;
    for (ll i = 1; i * i * i <= K; i++)
    {
        for (ll j = i;  i*j * j <= K; j++)
        {
            if ( K %(i*j) ==0){
                counter++;
            }
        }
    }
    cout << counter << endl;
}
     