#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include<set>
#include<map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
   int n,m;
   cin >> n >> m;
   
   vector< vector<bool> > takahashi(n, vector<bool>(n));      
   vector< vector<bool> > aoki(n, vector<bool>(n));
      
   int tmp1,tmp2;
   rep(i,m){
       cin >> tmp1 >> tmp2;
       tmp1--; tmp2--;
       takahashi[tmp1][tmp2] = takahashi[tmp2][tmp1] = true;
   }
   rep(i,m){
       cin >> tmp1 >> tmp2;
       tmp1--; tmp2--;
       aoki[tmp1][tmp2] = aoki[tmp2][tmp1] = true;
   }

    vector<int> p(n);    
    iota(p.begin(),p.end(),0);

    int ans = 0;
    do{        
        bool ok = true;

        rep(i, n){
            rep(j,n){
                if (takahashi[i][j] != aoki[p[i]][p[j]]){
                    ok = false;                                     
                }
            }
        }

        if (ok){
            cout << "Yes";
            return 0;
        }
    }while (next_permutation(p.begin(), p.end()));

    cout << "No";
    
      
   return 0;  

}