#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int func(int x)
{
   return x * x + 2 * x + 3;
}

int main()
{
   int total;

   cin >> total;

   vector<int> s(3);
   rep(i, 3)
   {
      s[i] = total % 10;
      total = total / 10;
   }

   cout << 111 * (s[0] + s[1] + s[2]);
}