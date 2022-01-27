#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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

ll total_sum(ll n, ll amari){
    /*
        1からnまでの総和        
    */
    return  (n * (n + 1) / 2) % amari;
}

int main(void)
{
    ll amari = 1E9 + 7;

    ll L, R;
    ll sum = 0;

    cin >> L >> R;
    string L_msg = to_string(L);
    string R_msg = to_string(R);

    int L_DIGIT = L_msg.size();
    int R_DIGIT = R_msg.size();

    cin >> L >> R;

    if (L_DIGIT == R_DIGIT){
        ll sum_l = total_sum(L-1,amari);
        ll sum_r = total_sum(R, amari);        
        sum = (sum_r - sum_l) % amari;        
    }
    else if (R_DIGIT - L_DIGIT == 1)
    {
        ll sum_lower_l =  (total_sum(L,amari)*L_DIGIT) % amari;
        ll lower_r = pow(10,amari) - 1;
        ll sum_lower_r = (total_sum(lower_r, amari) * L_DIGIT) % amari;
        ll sum_lower = (sum_lower_r - sum_lower_r);

        ll sum_upper_l = lower_r;
        ll sum_upper_r = 

        ll a = ((upper - L) * (L_DIGIT)) % amari;
        ll b = ((R + 1 - upper) * (R_DIGIT)) % amari;

        sum = (a + b) % amari;
    }
    else
    {
        // KURIAGE/
        ll upper = pow(10, L_DIGIT + 1), lower;

        ll a = ((upper - L) * (L_DIGIT)) % amari;
        ll b = ((R + 1 - upper) * (R_DIGIT)) % amari;

        sum = (a + b) % amari;

        ll mediam_sum = 0;

        for (int i = L_DIGIT + 1; i < R_DIGIT; i++){
            upper = pow(10, i);
            lower = pow(10, i + 1);
            mediam_sum += ((upper - lower - 1) * i) % amari;
        }

        sum = (sum + mediam_sum) % amari;
    }
    cout << sum;
}
     