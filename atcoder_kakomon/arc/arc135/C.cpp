
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

using namespace std;

#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;

ll sum = 0;

int main()
{
   int N;
   cin >> N;
   vector<ll> A(N+1);
   vector<ll> bit(33);

   ll max_sum = 0;


   rep(i,1,N){
      cin >> A[i];
      ll tmp = A[i];
      ll counter = 0;
      while(tmp != 0){
         if ((tmp &1) == 1){
            bit[counter]++;
         }
         tmp = (tmp >> 1);
         counter++;
      }
   }
   
   rep(i,0,32){
      // cout << bit[32 - i] <<" ";
      max_sum += bit[i] *(1<<i);
   }
   // cout <<endl;

   rep(i,1,N){
      ll tmp = A[i];
      ll counter = 0;
      ll sum = 0;

      rep(j,0,30){
         if ( ((A[i] >> j) &1) == 0){            
            sum += (1 << j)*bit[j];
         } else {
            sum += (1 << j)*(N - bit[j]);
         }         
      }
      // cout << sum <<endl;
      max_sum = max(max_sum, sum);
   }

   cout << max_sum<<endl;
}