#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int func(int x){
   return x * x + 2 * x + 3;
}

int main()
{
   int N;
   cin >> N;
   vector<int> A(N);

   rep(i,N){
      cin >> A[i];
   }

   int erase_number = A[N-1];
   rep(i, N - 1)
   {
      if (A[i] > A[i+1]){
         erase_number = A[i];
         break;
      }
   }

   rep(i,N){
      if (A[i]!=erase_number){
         cout << A[i] << " ";
      }
   }
}