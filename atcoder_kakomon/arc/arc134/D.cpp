#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

typedef pair<ll, ll> P;

int main()
{
   int N;
   cin >> N ;

   vector<ll> A(2*N);
   priority_queue<P, vector<P>, greater<P>> pque;

   rep(i,2*N){
      cin >> A[i];
      if (i <N){
         pque.push(P{A[i],i});
      }
   }
   

   vector<ll> before, after;
   ll left = 0;
   while (!pque.empty())
   {
      P best = pque.top();
      pque.pop();
      if (before.size() == 0)
      {

         ll idx = best.second;
         before.push_back(A[idx]);
         after.push_back(A[N+idx]);
         left = idx;
      }
      else if (left > best.second)
      {
         continue;
      } else {
         ll value = best.first;

         if (value < after[0]){
            before.push_back(value);
            after.push_back(A[N+best.second]);
            left = best.second;
         }
         else if (value > after[0])
         {
            continue;
         }
         else
         {
            ll flag = -1;

            for (ll j = 0; j < (ll)after.size()-1;j++){
               if (after[j] < after[j+1]){
                  flag = 1; // insertする
               } else if (after[j] > after[j+1]){
                  flag = -1; //insertしない
               }
            }
            if (flag == -1){
               continue;
            } else {
               before.push_back(value);
               after.push_back(A[N + best.second]);
               left = best.second;
            }
         }
      }
   }

   for(ll a: before){
      cout << a << " ";
   }
   for (ll b : after)
   {
      cout << b << " ";
   }
}