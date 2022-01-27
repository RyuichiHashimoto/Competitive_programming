#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

using namespace std;

vector<int> V[10000];

int main()
{
   int L, R;
   string massage;

   cin >> L >> R;
   cin >> massage;
   L--;
   R--;

   for (int i = 0; i < L;i++){
      cout << massage[i];
   }

   for (int i = L; i <= R; i++)
   {
      cout << massage[R - i+L];
   }

   for (int i = R+1; i < massage.size(); i++)
   {
      cout << massage[i];
   }
}