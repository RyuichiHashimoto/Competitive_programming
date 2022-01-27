#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int MAX_N = 1E5;



int main(void)
{
    ll array[MAX_N * 2];
    ll N;

    cin >> N;

    ll sum = 0;
    rep(i, N)
    {
        cin >> array[i];
        array[i + N] = array[i];
        sum += array[i];
    }

    int start = 0, end = 0;

    ll ans = array[0];
    bool find_flag = false;

    while ( !(start >= N or end == 2*N)){  

        if (ans*10 == sum){
            find_flag = true;
            break;
        } else if (ans*10 > sum){
            ans -= array[start];
            start++;
        }
        else if (ans * 10 < sum)
        {
            end++;
            ans += array[end];
        }

    }
    if (find_flag){
        cout << "Yes";
    } else {
        cout << "No";
    }
}
    