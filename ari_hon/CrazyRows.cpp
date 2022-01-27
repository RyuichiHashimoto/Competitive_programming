#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int find_last_1_position(string row){

    for (int i = row.size(); i >= 0;i--){
        if (row[i] == '1'){
            return i;
        }
    }
    return 0;
}

int main(){

    int n;
    cin >> n;

    vector<string> row(n);
    // priority_queue<P,vector<P> > pque;
    priority_queue<P, vector<P>, greater<P>> pque;

    int **matrix = new int *[n];

    for (int i = 0; i < n;i++){
        cin >> row[i];
        int last_1_idx = find_last_1_position(row[i]);
        P p(last_1_idx * 40 + i,i);
        
        pque.push(p);
    }

    int swap_counter = 0;
    for (int i = 0; i < n; i++)
    {
        P p = pque.top();
        pque.pop();
        
        int target_idx = p.second;

        if (target_idx > i)
        {
            swap(row[target_idx], row[i]);
            swap_counter++;
        }
    }
    
    for (int i = 0; i < row.size(); i++)        
    {
        cout << row[i]<<endl;
    }
        cout << swap_counter;
}
