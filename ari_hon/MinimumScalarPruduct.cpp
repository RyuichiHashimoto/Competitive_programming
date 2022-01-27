#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

typedef long long ll;

int main(){

    int n = 5;

    ll v1[] = {1 , 2, 3, 4, 5};
    ll v2[] = {1, 0, 1, 0, 1};

            
    sort(v2, v2 + n, greater<ll>{});
    sort(v1, v1 + n);

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v1[i] * v2[i];
    }
    cout << sum << endl;
}
