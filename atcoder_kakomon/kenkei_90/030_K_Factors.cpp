#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef unsigned long long ll;


int Eratosthenes(int N,int K)
{        
    if (K ==1 ){
        return N - 1;
    }

    int *is_prime = new int[N+1];
    fill(is_prime, is_prime + (N+1), 0);
    int counter = 0;

    for (int i = 2;i<=N;i++){
        if (is_prime[i] == 0){
            for (int j = 1; j * i <= N;j++){
                is_prime[i * j]++;
            }
        }else {
            if (is_prime[i]>= K){
                counter++;
            }
        }
    }

    delete is_prime;
    return counter;
}

int main(void)
{
    int N, K;
    cin >> N>>K;

    cout << Eratosthenes(N, K);
}