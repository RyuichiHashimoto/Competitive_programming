#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


const int MAX_N = 1E6+1;
ll res[MAX_N];

vector<ll> divisor(ll number)
    {
        /*
            数字 numberの約数を小さい順に列挙                    
            計算量: sqrt(number);

        */
        vector<ll> res;

        for (ll i = 1; i * i <= number; i++)
        {

            if (number % i == 0)
            {
                res.push_back(i);
                if (i * i != number)
                {
                    res.push_back(number / i);
                }
            }
        }
        return res;
    }



int main()
{
    ll number;
    cin >> number;

    vector<ll> array =divisor(number);  
    sort(array.begin(),array.end());

    for(ll a: array){
        // cout << a <<endl;
    }
    // cout << endl;
    ll sum = 0;
    
    if ( array.size() ==1){
        cout <<1;
    } else if (array.size() == -1){
        cout << (array[1]- array[0])*array[0] + array[1];
    } else {          
        for(int i=0;i< array.size()-1;i++){
            // cout << (array[i+1] - array[i])*(number/array[i+1])<<endl;
            sum += (array[i+1] - array[i])*(number/array[i+1]);
        }   
        sum += array[array.size()-1];
        cout << sum;
    }

  
}