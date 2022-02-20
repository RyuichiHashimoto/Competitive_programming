#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define rep(i,from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

const int MAX_N = 1.0E5;

ll height[MAX_N];
ll diff[MAX_N];

int main(void)
{
    ll x1,y1,x2,y2;

    cin >> x1 >>  y1 >> x2 >> y2;

    x2 = x2 - x1; 
    y2 = y2 - y1; 

    x1 = x1 -x1;
    y1 = y1 -y1;

    
    ll x_list[] = {2, 1, -1, -2 ,-2 , -1 , 1, 2};
    ll y_list[] = {1, 2, 2, 1, -1, -2, -2, -1};

    bool find_flag  = false;
    rep(i,0,7){
        ll x_dif = x_list[i] - x2;
        ll y_dif = y_list[i] - y2;

        ll distance = (x_dif)*x_dif + y_dif *y_dif;
        if (distance == 5){
            find_flag = true;
            break;
        }
    }
    if (find_flag){
        cout << "Yes";
    }else{
        cout << "No";
    }
    


    


   
}