#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cassert>
#include <numeric>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


typedef long long ll;

int main(void)
{
    ll N, K;

    cin >> N >> K;
    ll amari = 1E5;

    if (N==0){
        cout << 0;
    } else {
        const int MAX_N = 1E5 + 1;
        int next[MAX_N];
        int first_time[MAX_N];

        fill(next, next + MAX_N, 0);
        fill(first_time, first_time + MAX_N, -1);

        ll i;
        for (i = 1; i <= K; i++)
        {
         
            if (first_time[N] == -1)
            {
                first_time[N] = i;
            }
            else
            {
                ll interval = i - (ll)first_time[N];

                ll b = (K - first_time[N]) / (interval);
                i = first_time[N] + interval*(b);
                for (ll j = i; j <= K; j++)
                {

                    N = next[N];
                }
                break;
            }

            int tmp = N;
            int second_value = 0;

            while(tmp != 0){
                second_value += tmp % 10;
                tmp /= 10;
            }
            next[N] = (N + second_value) % amari;
            N = next[N];
        }

            cout << N << endl;        
    }
}