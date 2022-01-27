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
   vector<int> height(N);
   

   int tmp = 0;
   int max_height = -1;
   rep(i, N)
   {
      cin >> tmp;

      if (tmp > max_height)
      {
         max_height = tmp;         
      } else {         
         break;
      }
   }
   cout << max_height;
}