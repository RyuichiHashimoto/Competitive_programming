#include <iostream>
#include <bits/stdc++.h>
#include<map>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

typedef pair<ll, ll> P;

int main(void)
{
    int N;
    cin >> N;
    map<string, int> regist;

    rep(i,N){
        string tmp;
        cin >> tmp;
        if (regist[tmp] == 0){
            regist[tmp]++;
            cout << i + 1 << endl;
        }
    }
}