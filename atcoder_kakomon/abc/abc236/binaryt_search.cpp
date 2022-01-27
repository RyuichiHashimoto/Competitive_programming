#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;


int main(){

   int N = 10;
   vector<int> A(N);

   for (int i = 0; i < N;i++){
      A[i] = 2 * i;
   }

   int lb = 0;
   int rb = N - 1;
   int target_value = 10;
   int answer = -1;

   while (rb -lb != 1){
      int mid = (lb + rb) / 2;

      if (A[mid]< target_value){
         lb = mid;
      } else if (A[mid] > target_value){
         rb = mid;
      }else{
         lb = mid;
         break;
      }
   }
   cout << lb << " " << A[lb] << endl;
}