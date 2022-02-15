#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

const int MAX_N = 1.0E5;

ll height[MAX_N];
ll diff[MAX_N];

int main(void)
{
    int N;
    cin >> N;

    vector<int> L(N+1);
    vector<int> R(N+1);


    rep(i,1,N){
        cin >> L[i] >> R[i];
    }

    double ret = 0;
    rep(i,1,N){        
        rep(j,i+1,N){
            int sum=0 , all=0;
            rep(k,L[i],R[i]){
                rep(l,L[j],R[j]){
                    if (k > l){
                        sum++;
                    }
                    all++;
                }
            }
            ret += (double)sum/all;
        }
    }
    cout.precision(15);
    cout  << ret<<endl;

    

    


   
}