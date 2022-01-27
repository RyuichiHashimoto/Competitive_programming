#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<time.h>
using namespace std;

typedef long long ll;

int main(){

    ll ans = -1;;
    int N = 3;
    int L[] = {8, 5, 8};

    priority_queue<int, vector<int>, greater<int>> que;

    for (int i = 0; i < N;i++){
        que.push(L[i]);        
    }
    int cost = 0;
    while (que.size() > 1)
    {
        int l1, l2;

        l1 = que.top();
        que.pop();
        l2 = que.top();
        que.pop();

        int l = l1 + l2;
        que.push(l);
        cost += l;
    }
    cout << cost;
}