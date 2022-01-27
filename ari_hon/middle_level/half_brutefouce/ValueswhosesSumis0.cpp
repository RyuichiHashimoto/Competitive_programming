#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>

using namespace std;
typedef long long ll;

void read_each_line(int *a,int n){

    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    
}

int main(){

    int n;
    cin >> n;

    int *a = new int[n];
    int *b = new int[n];
    int *c = new int[n];
    int *d = new int[n];

    read_each_line(a, n);
    read_each_line(b, n);
    read_each_line(c, n);
    read_each_line(d, n);

    int *cd = new int[n * n];

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n; j++)
        {
            cd[i * n + j] = c[i] + d[j];
        }
    }
    ll res = 0;
    sort(cd, cd + n * n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)        
        {
            // upper_bound
            int target_cd = -(a[i] + b[j]);

            res += (ll)(upper_bound(cd, cd + n * n, target_cd) - lower_bound(cd, cd + n * n, target_cd));
        }
    }

    cout << res;

    delete a;
    delete b;
    delete c;
    delete d;
    delete cd;
}
