#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef pair<int, int> P;

int main(){

   int N;
   string S;

   cin >> N;
   cin >> S;

   list<int> lst(1,0);

   int last_value_pos = 0;

   auto itr = lst.begin();
 
   if (S[0]=='L'){
      itr = lst.begin();
      itr = lst.insert(itr, 1);
   }
   else
   {
      itr = lst.end();
      itr = lst.insert(itr, 1);
   }

   for (int i = 1;i<N;i++){
      if (S[i] == 'R'){
         itr++;
      }

      itr = lst.insert(itr, i + 1);
   }
   for (auto s : lst){
      cout << s << " ";
   }
}