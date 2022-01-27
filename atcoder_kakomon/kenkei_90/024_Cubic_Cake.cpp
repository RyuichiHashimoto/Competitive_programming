#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

typedef pair<ll, ll> P;

int main(void)
{
    int N,K;

    cin >> N >> K;

    vector<int> A(N),B(N);

    rep(i,N){
        cin >> A[i];
    }

    rep(i, N)
    {
        cin >> B[i];
    }
    int haming_distance = 0;

    rep(i,N){
        haming_distance += abs(A[i]-B[i]);
    }
    if (haming_distance <= K && ((K - haming_distance) %2 == 0 )){
        cout << "Yes";
    } else {
        cout << "No";
    }
 }