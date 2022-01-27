#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> sinsuu(500000);

int main(void){
   string massage;
   cin >> massage;
   int n = massage.size();
   
   sinsuu[n-1] = massage[0] - '0';

   for (int i = 0; i < n; i++)
   {      
      sinsuu[n - (i + 1) -1 ] = sinsuu[n - (i) - 1 ] + (massage[i+1] - '0');      
   }

   int len;
   for (int i = 0;; i++)
   {
      if (sinsuu[i] >= 10){
         sinsuu[i + 1] = sinsuu[i + 1]  + sinsuu[i] / 10;
         sinsuu[i] = sinsuu[i] % 10;
      } else {
         if (sinsuu[i] == 0){
            len = i;
            break;
         }
      }
   }
   for (int i = 0; i < len;i++){
      cout << sinsuu[len - i-1];
   }
}