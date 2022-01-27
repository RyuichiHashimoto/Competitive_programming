#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <set>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

typedef long long ll;

struct memo{
   vector<bool> used;
   ll sum;
   ll match_count;
   int next_person;
};

int
main()
{
   int N;
   cin >> N;
   vector<vector<ll>> mat(2*N);

   rep(i, 2 * N)
   {
      mat[i].resize(2 * N);
      fill(mat[i].begin(), mat[i].end(), 0);
   }

   for (int i = 0; i < 2 * N; i++)
   {
      for (int j = i + 1; j < 2 * N; j++)
      {
         ll tmp;
         cin >> tmp;
         mat[i][j] = tmp;
         mat[j][i] = tmp;
      }
   }
   vector<bool> b(2*N);

   queue<memo> que;
   memo first{b, 0, 0,0};
   que.push(first);
   int a = 0;

   ll max_val = -1;
   while (!que.empty())
   {
      memo current = que.front();
      que.pop();

      

      if (current.match_count == N){       
         max_val = max(max_val, current.sum);
      } else {
         int first_person = current.next_person;
            
      
         for (int i = first_person+1; i < 2 * N;i++){
            vector<bool> tmp_used = current.used;
            if (tmp_used[i]){
               continue;
            }

            tmp_used[i] = true;
            tmp_used[first_person] = true;
            ll sum = current.sum ^ mat[i][first_person];

            int ne = current.next_person;
            while (tmp_used[ne])
            {
               ne++;
            }
            memo s{tmp_used,sum,current.match_count +1,ne};
            que.push(s);
         }
      }      
   }
   cout << max_val;
}