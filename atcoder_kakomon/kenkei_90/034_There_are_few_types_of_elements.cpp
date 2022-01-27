#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

typedef pair<int, int> P;


int main(void)
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    vector<P> array;

    rep(i,N){
        cin >> A[i];
    }

    int from = 0;
    int to = 0;

    int max_value = -1;
    map<int, int> B;
    int kind = 0;
    int cr = 0;

    rep(i, N)
    {
        
        while (cr < N){
            if (B[A[cr]] == 0 && kind == K)
            {
                break;
            }
            if (B[A[cr]] == 0)
            {
                kind++;
            }
            B[A[cr]]++;
            cr++;
        }

        max_value = max(max_value, cr - i);

        B[A[i]]--;
        if (B[A[i]] == 0){
            kind--;
        }
    }
    cout << max_value;
}