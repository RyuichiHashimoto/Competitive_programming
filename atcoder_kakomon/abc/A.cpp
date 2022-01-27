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
   int t = 0;

   cin >> t;

   int f_t = func(t);
   
   int f_t_2 = func(f_t + t);

   int f_t_3 = func(f_t);

   cout << func(f_t_2 + f_t_3);
}