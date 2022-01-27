#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

ll amari = 1E9 + 7;

int main(void)
{
    const int max = 100001;

    ll K;
    cin >> K;
    if (K % 9 != 0){
        cout << 0 << endl;
    } else {
        ll array[100001];
        fill(array, array + max, 0);
        array[0] = 1;

        for (int i = 1; i <= K;i++){
            for (int m = 1; m <= 9; m++){        
                if (i - m >= 0){
                    array[i] = (array[i] + array[i - m]) % amari;
                }
            }
        }
        cout << array[K] << endl;
    }
}