#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

vector<vector<ll>> mat;

int dfs(vector<vector<ll>> &mat, vector<bool> &used, ll sum, int who,int N){

   if (who == N){
      return sum;
   }
   ll max_val = -1;
   for (int i = who + 1; i < N; i++)
   {
      if (!used[i]){
         used[i] = true;
         sum = sum ^ mat[who][i];
         max_val = max(max_val, sum);
      }
   }
   return max_val;
}

int main()
{
   int N;

   cin >> N;
   vector<ll> A(N);

   rep(i,N){
      cin >> A[i];
   }

   // first_pert;
   priority_queue<ll,vector<ll>> otherwize;
   vector<ll> median;
   int counter = 0;
   ll sum = 0;

   for (int i = 0; i < N;i++){

      if (i % 2 == 1){
         sum += A[i];
         counter++;
         median.push_back(A[i]);
      } else {
         otherwize.push(A[i]);
      }
   }
   sort(median.begin(), median.end());

   bool break_flag1 = false, break_flag2 = false;
   int added_counter = 0;

   ll current_max=-1;

   while (!break_flag1 && !break_flag2 &&  !otherwize.empty()){
      current_max = otherwize.top();
      otherwize.pop();

      if (!break_flag1){
         if ( (double)sum/counter < current_max){
            sum += current_max;
            counter++;
         } else {
            break_flag1 = true;
         }
      }

      if (!break_flag2){
         ll median_val = median[(int)median.size() / 2];

         if (median_val <= current_max){
            median.push_back(current_max);            
         }
      }
   }
   cout << (double)sum / counter<<endl;

   rep(i,median.size()){
      cout << median[i] << " ";
   }

   cout << endl;

   cout << median[(int)median.size() / 2];
}