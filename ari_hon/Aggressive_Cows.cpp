#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

bool check(int d, int n_cows,int* barn_position, int n_barns){

    int last = 0;
    int counter = 0;
    
    for (int i = 0; i < n_cows;i++){
        int target_pos = last + 1;

        while ( target_pos < n_barns && (d > (barn_position[target_pos] - barn_position[last]))){
            target_pos++;
        }

            last = barn_position[i];            
            if (target_pos == n_barns)
                return false;
    }

    return true;
}

int main(){

    int N = 5;
    int M = 3;
    int X[] = {1, 2, 8, 4, 9};

    sort(X, X + N);

    int lb = 0, ub = 0x7FFFFFFF;    
    
    while ( (ub - lb) > 1 ){                
        int mid = (ub + lb) /2;
        cout << mid << " " << ub << " " << lb<<endl;

        if(check(mid,M,X,N)){
            lb = mid;
        } else{
            ub = mid;
        }
    }
    cout << lb;
}
