#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int ctoi(char a){
    return a - '0';
}

#define rep(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;

int main()
{
    int n, m;

    int *a, *b;
    cin >> n >> m;

    a = new int[n];
    b = new int[m];

    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    int a_idx = 0, b_idx = 0;
    int minimum = 0x7FFFFFFF;

    while ( (a_idx < n) && (b_idx < m)){
        minimum = min(minimum, abs(a[a_idx] - b[b_idx]));
                        
        if ( a[a_idx] < b[b_idx] ){
            a_idx++;
        } else {
            b_idx++;
        }
    }
    cout << minimum;

    delete a;
    delete b;
}