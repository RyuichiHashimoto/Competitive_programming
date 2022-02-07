#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

int main()
{
   int N;
   cin >> N;
   vector<int> vec(N);
   vector<int> sum(N);
   
   rep(i,N){
      cin >> vec[i];
   }
   sum[0] = 90;
   rep(i,N){      
      sum[i] = (sum[i-1] + vec[i]) % 360;      
   }

   sort(sum.begin(),sum.end());

   int max_val = sum[0];

   for(int i=0;i<N-1;i++){
      max_val = max(max_val,sum[i+1]-sum[i]);
   }
   max_val = max(max_val, 360-sum[N-1]);

   cout << max_val<<endl;







}