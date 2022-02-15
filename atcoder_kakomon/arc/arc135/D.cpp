
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int MAX_N = 1<<20;

typedef long long ll;

ll next_idx[MAX_N];
ll value[MAX_N];

int main()
{
   int Q;

   cin >>Q;


   fill(value,value+MAX_N,-1);
   rep(i,MAX_N){
      next_idx[i] = (i+1)%MAX_N;
   }
   rep(i,Q){
      ll t,x;
      cin >> t >> x;

      if (t == 1){
         ll inserted_idx= x % MAX_N;

         while (value[inserted_idx] != -1){
            inserted_idx = next_idx[inserted_idx] % MAX_N;
         }
         // cout << inserted_idx<<" " <<x<<endl;
         value[inserted_idx] = x;
         next_idx[(x%MAX_N)] = next_idx[inserted_idx];
      } else{
         cout << value[ x%MAX_N]<<endl;
      }
   }

   rep(i,10){
      // cout <<value[i]<<" ";
   }
   // cout <<endl;
   rep(i,10){
      // cout <<next_idx[i]<<" ";
   }





}