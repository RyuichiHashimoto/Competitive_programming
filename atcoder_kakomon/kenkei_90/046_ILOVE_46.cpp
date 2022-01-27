#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cassert>
#include <numeric>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef unsigned long long ll;



int main(void)
{
    int N;
    cin >> N;

    ll A_count[46];
    ll B_count[46];
    ll C_count[46];

    fill(A_count, A_count + 46, 0);
    fill(B_count, B_count + 46, 0);
    fill(C_count, C_count + 46, 0);

    int tmp;
    
    rep(i, N)
    {
        cin >> tmp;
        tmp = tmp % 46;
        A_count[tmp]++;        
    }
    
    rep(i, N)
    {
        cin >> tmp;
        tmp = tmp % 46;
        B_count[tmp]++;
    }    
    rep(i,N){
        cin >> tmp;
        tmp = tmp % 46;
        C_count[tmp]++;
    }
    

    ll  counter = 0;
    for (int a_i = 0; a_i < 46; a_i++)
    {
        for (int b_i = 0; b_i < 46; b_i++)
        {
            for (int c_i = 0; c_i < 46; c_i++)
            {
                int s = (a_i + b_i + c_i) % 46;
                if (s == 0)
                {
                    counter += A_count[a_i] * B_count[b_i] * C_count[c_i];
                }

                
            }
        }
    }
    cout << counter << endl;
}