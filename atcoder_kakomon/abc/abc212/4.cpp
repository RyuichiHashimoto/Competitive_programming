#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;

int main()
{        
    priority_queue<ll,vector<ll>,greater<ll>> pque;

    ll minus = 0;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q;i++){
        int query;
        ll number = -1;

        cin >> query;

        
        if (query == 1)
        {            
            cin >> number;            
            pque.push(number - minus);
        }
        else if (query == 2)
        {
            cin >> number;                        
            minus += number;
        }
        else if (query == 3)
        {
            ll top = pque.top();
            pque.pop();
            cout << top + minus << endl;
        }
    }

}