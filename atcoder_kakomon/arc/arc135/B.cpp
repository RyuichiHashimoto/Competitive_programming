
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

using namespace std;

#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

int main()
{
   int N;
   cin >> N;
   vector<ll> S(N+1);
   vector<ll> diff_S(N+1);

   vector<ll> A_1;
   vector<ll> A_2;
   vector<ll> A_3;

   rep(i,1,N){
      cin >> S[i];
   }
   rep(i,1,N-1){
      diff_S[i] = S[i+1] - S[i];
   }
   ll last_a1 = 0,last_a2 = 0,last_a3 = 0;

   ll min_a1 = 0,min_a2 = 0,min_a3 = 0;
      
   rep(i,4,N+2){      
      if (i %3 == 1){         
         last_a1 = last_a1 + diff_S[i-3];
         min_a1 = min(min_a1,last_a1);
      }  else if (i %3 == 2){
         last_a2 = last_a2 + diff_S[i-3];
         min_a2 = min(min_a2,last_a2);
      }  else if (i %3 == 0){
         last_a3 = last_a3 + diff_S[i-3];
         min_a3 = min(min_a3,last_a3);
      }
   }
   ll min_value = -1 * (min_a1 + min_a2 + min_a3);
   if (min_value  > S[1]){
      cout << "No";
   } else {
      last_a1 = -1*min_a1,last_a2 = -1*min_a2;
      last_a3 = S[1] - (last_a1 + last_a2);      
      cout <<"Yes"<<endl;
      cout << -1 *min_a1 <<" " << -1 * min_a2 << " " <<  last_a3<<" ";      

      rep(i,4,N+2){
         if (i %3 == 1){
            last_a1 = last_a1 + diff_S[i-3];            
            cout << last_a1 << " ";
         } else if (i %3 ==2){
            last_a2 = last_a2 + diff_S[i-3];            
            cout << last_a2 << " ";
         } else if (i %3 ==0){
            last_a3 = last_a3 + diff_S[i-3];            
            cout << last_a3 << " ";            
         }
      }
   }


}