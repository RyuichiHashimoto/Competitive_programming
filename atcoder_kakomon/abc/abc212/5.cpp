#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int **a = new int*[M];
    rep(i, M) a[i] = new int[2];
    rep(i, M) cin >> a[i][0] >> a[i][1];


    


    rep(i, M) delete a[i];
    delete a;    
}