#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef pair<int, int> P;

int main()
{
   int N;
   string s;
   cin >> N;
   cin >> s;
   priority_queue<P,vector<P>,greater<P>> pque;

   for (int i = 0;i<N;i++){
      pque.push(P(s[i]-'a', -1*i));
   }
   vector<P> swap_pair;
   int left = 0;
   int right = N;
   while (!pque.empty())
   {
      P p = pque.top();
      pque.pop();
      int best_chara_idx = p.second * -1;

      while ( (left < best_chara_idx) && (s[left] - 'a') <= p.first)
      {
         left++;
      }
      if (left < best_chara_idx && best_chara_idx < right){


         swap_pair.push_back(P{left, best_chara_idx});
         left++;
         right = best_chara_idx;
      }
   }
   for(P p : swap_pair){
      swap(s[p.first], s[p.second]);
   }
   cout << s;
}