#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

const int MAX_N = 1.0E5;

ll height[MAX_N];
ll diff[MAX_N];

int main(void)
{
    ll x;
    cin >> x;

    if (x == 0){
        cout << 0<<endl;
    } else if (x > 0){
        cout << x/10<<endl;
    } else if (x < 0){
        if (x%10==0){
            cout << x/10 <<endl;
        } else {
            cout << x/10 - 1<<endl;
        }
        
    }


}