#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(void)
{
    int N;
    cin >> N;

    vector<int> school(N);
    vector<int> child(N);

    rep(i,N){
        cin >> school[i];
    }

    rep(i, N)
    {
        cin >> child[i];        
    }
    sort(school.begin(), school.end());
    sort(child.begin(), child.end());

    ll sum = 0;

    rep(i,N){
        sum += abs(child[i] - school[i]);
    }
    cout << sum;
}