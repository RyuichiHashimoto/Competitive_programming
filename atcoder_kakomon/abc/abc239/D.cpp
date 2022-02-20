#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

 vector<int> Eratosthenes(int N)
    {
        vector<int> prime_list;

        bool *is_prime = new bool[N+1];
        fill(is_prime, is_prime + N, true);

        for (int i = 2; i <= N; i++)
        {
            if (is_prime[i])
            {
                prime_list.push_back(i);

                for (int j = 1; j * i <= N; j++)
                {
                    is_prime[i * j] = false;
                }
            }
        }
        delete is_prime;
        return prime_list;
    }

int main(void)
{

    vector<int> prime_list = Eratosthenes(200);


    int a,b,c,d;
    cin >> a >> b >> c >> d;


    bool find_flag = false;    
    rep(i, a,b){
        int minimum = i + c;

        auto s = lower_bound(prime_list.begin(),prime_list.end(),minimum);
        int val = *s;

        if (val <=  i + d){
            
        } else {
            cout << "Takahashi";
            return 0;
        }
    }

    cout << "Aoki"<<endl;



   
}