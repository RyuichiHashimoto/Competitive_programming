#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

typedef pair<int, int> P;

int main()
{   
   int a, K;

   cin >> a >> K;
   
   queue<P> que;

   que.push(P(1,0));

   bool break_flag = false;
   int digit = to_string(K).size();

   map<int, int> d;

   d[1] = 1;

   int objective = -1;
   while (!(que.empty()))
   {
      P p = que.front();
      int val = p.first;
      int time = p.second;
      que.pop();
      // cout << val << " " << time << endl;

      if (val == K)
      {
         // break_flag = true;
         objective = time;
         break;
      }
      else
      {
         string name = to_string(val);
         if ( (val >= 10) && (val %10 != 0)){                                    
            if (name.size() <= digit){
                              
               rotate(name.begin(), name.begin() + name.size() - 1, name.end());
               if (d[stoi(name)] == 0){
                  d[stoi(name)] = 1;
                  que.push(P(stoi(name), time + 1));
               }
               
               
            }
         }
         int k = val * a;
         if (to_string(k).size()<=digit){
            que.push(P(k, time+1));
         }
      }
   }
   cout << objective;

   // cout << pque.top() << endl;
}