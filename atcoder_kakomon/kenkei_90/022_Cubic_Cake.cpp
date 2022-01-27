#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

typedef pair<ll, ll> P;

int main(void)
{
    ll A, B, C;

    cin >> A >> B >> C;

    ll max_, min_;
    ll ori_A=A, ori_B=B, ori_C=C;
        
    while (!((A == B) && (B == C)))
    {
        ll min_val = min({A, B, C});
        ll max_val = max({A, B, C});

        while (!(max_val %min_val == 0)){
            min_val = max_val % min_val;                                
        }
        
        if (max_val == A)
        {
            A = min_val;
        }
        else if (max_val == B)
        {

            B = min_val;
        }
        else
        {
            C = min_val;
        }        
    }

    cout << ori_A /A + ori_B/B + ori_C / C-3;
    // cout <<
}