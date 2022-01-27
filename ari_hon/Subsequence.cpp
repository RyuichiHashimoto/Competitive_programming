#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

typedef long long ll;

int main(){

    int n = 10;
    int S = 15;
    int a[] = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};

    int *sum = new int[n+1];

    for (int i = 0; i < n+ 1; i++)
        sum[i+1] = sum[i ] + a[i];

    if(sum[n] < S){
        cout << "0";
        return 0;
    }
    int res = n;

    for (int s = 0; sum[s] + S <= sum[n];s++){
        int t = lower_bound(sum + s, sum + n, sum[s] + S) - sum;
        cout << lower_bound(sum + s, sum + n, sum[s] + S)<<endl;

        res = min(res, t - s);
    }
    delete sum;
    cout << res;
}
