#include <iostream>
using namespace std;
#include <limits.h>
#include <queue>


namespace primenumber {
    



}

typedef long long ll;
typedef pair<ll,ll> p

vector<int> Eratosthenes_Sieve(int n)
{
    /*
        return prime numbers in [0, n] as vector<int> type;
    */

    bool *is_prime = new bool[n];
    vector<int> prime_list;
    fill(is_prime, is_prime + n + 1, 1);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime_list.push_back(i);
        
            for (int j = i * 2; j <= n; j = j + i)
            {
                is_prime[j] = false;
            }
        }
    }
    delete is_prime;
    return prime_list;
}


int main(void)
{

    ll a = 22801763489;
    ll b = 22801787297;    
}