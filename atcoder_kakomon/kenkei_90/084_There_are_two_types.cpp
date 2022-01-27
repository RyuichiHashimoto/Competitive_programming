#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;


int main(void)
{
    ll N;
    cin >> N;
    string name;
    cin >> name;


    ll sum = 0;
    
    for (ll i = 0; i < N;)
    {
        char target_moji = name[i];

        ll j = i + 1;

        while ( j != N  &&  target_moji == name[j])
            j++;

        sum += (N - j) * (j - i);
        i = j;
    }
    cout << sum;
}
     