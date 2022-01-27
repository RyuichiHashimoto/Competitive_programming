#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){

    int N;
    cin >> N;
    vector<int> A(N);

    rep(i, N){
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    
    int Q, tmp;
    cin >> Q;

    rep(i, Q)
    {
        cin >> tmp;

        if (tmp < A[0]){            
            cout << abs(A[0] - tmp) << endl;
        } else{        
            auto p = upper_bound(A.begin(),A.end(),tmp);
            auto q = p - 1;                
            int minimum = min(abs(*(p - 1) - tmp), abs(*p - tmp));
            cout << minimum<<endl;
        }
    }
}