#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <cassert>
#include <numeric>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef unsigned long long ll;

ll gcd(ll a,ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

const int max_size = 4.0 * 1.0E5;
int ARRAY[max_size];

int main(void)
{
    int N, Q;
    cin >> N >> Q;
    // cout << max_size;

    int start_point = 2.0E5;
    int end_point = start_point;
    
    rep(i,N){
        end_point++;
        cin >> ARRAY[start_point + i];
    }

    rep(i,Q){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        tmp2--;
        tmp3--;

        if (tmp1 == 1){
            int tmp = ARRAY[start_point + tmp2];
            ARRAY[start_point + tmp2] = ARRAY[start_point + tmp3];
            ARRAY[start_point + tmp3] = tmp;
        } else if (tmp1 == 2){
            ARRAY[start_point - 1] = ARRAY[end_point - 1];
            end_point--;
            start_point--;
        } else if (tmp1 == 3){
            cout << ARRAY[start_point + tmp2] << endl;
        }
        rep(i,N){
            // cout << ARRAY[start_point+i] << " ";
        }
        // cout << endl;
    }
}