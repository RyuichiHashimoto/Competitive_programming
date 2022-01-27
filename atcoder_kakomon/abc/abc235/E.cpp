#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

bool check(vector<int> &x){

   int base = x[1] - x[0];
   for (int i = 2; i < x.size(); i++)
   {
      if (  (x[i] - x[i - 1]) != (x[i-1] - x[i - 2])){
            return false;
         }
   }
   return true;
}

int main()
{
   ll x;
   cin >> x;

   if (x /10 == 0){
      cout << x;
   }
   if (x /100==0){
      cout << x;
   }



   vector<int> tmp_x;
   vector<int> array_x;

   int counter = 0;
   while (x != 0)
   {
      tmp_x.push_back(x % 10);
      x = x / 10;
   }
   rep(i,tmp_x.size()){
      array_x.push_back(tmp_x[tmp_x.size() - 1 - i]);
   }

   while (1){
      int base = array_x[1] - array_x[0];
      bool break_flag = true;
      int bef_value = array_x[1];

      for (int i = 2; i < array_x.size();i++){
         

         if (base != array_x[i] - array_x[i - 1])
         {
            break_flag = false;

            int dif = array_x[i - 1] + base;
            
            if (dif >= 10)
            {
               array_x[i] = dif;
               array_x[i - 1]++;

               for (int k = i; k < array_x.size();k++){
                  array_x[k] = 0;
               }
               
               for (int k = i - 1; k >= 0;k--){
                  if (array_x[k] >= 10){
                     array_x[k] = 0;
                     array_x[k-1]++;
                  }
               }
               break;
            }
            else if (dif < 0){
               array_x[i] = bef_value;
               array_x[i - 1]++;               
               
               for (int k = i; k < array_x.size(); k++)
               {
                  array_x[k] = 0;
               }

               for (int k = i - 1; k >= 0; k--)
               {
                  if (array_x[k] >= 10)
                  {
                     array_x[k] = 0;
                     array_x[k - 1]++;
                  }
               }
               for (int i = 0; i < array_x.size(); i++)
               {
                  cout << array_x[i] << " ";
               }
               cout << endl;
               break;
            } else {
               bef_value = array_x[i];
               array_x[i] = dif;
            }

            
         }
      }
      if(break_flag){
         break;
      }
      for (int i = 0; i < array_x.size(); i++)
      {
         cout << array_x[i] << " ";
      }
      cout << endl;
   }

   for (int i = 0; i < array_x.size();i++){
      cout << array_x[i]<<" ";
   }
}