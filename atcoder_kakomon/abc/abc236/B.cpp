#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main()
{

   int N;

   cin >> N;   
   vector<int> tranp(N+1);
   fill(tranp.begin(), tranp.end(), 0);

   rep(i,4*N-1){
      int value;
      cin >> value;

      tranp[value]++;
   }

   rep(i,N){
      if (tranp[i+1] == 3){
         cout << i + 1;
      }
   }

}