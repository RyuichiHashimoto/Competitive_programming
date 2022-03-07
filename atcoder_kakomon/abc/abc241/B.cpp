#include <bits/stdc++.h>

#include <iostream>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

const int MAX_N = 1.0E5;

ll height[MAX_N];
ll diff[MAX_N];

int main(void) {

    int N, M;

    cin >> N >> M;


    priority_queue<int, vector<int>, greater<int>> A_que;
    vector<int> B(M + 1);

    rep(i, 1, N) {
        int tmp;
        cin >> tmp;
        A_que.push(tmp);
    }

    rep(i, 1, M) {
        cin >> B[i];
    }

    sort(B.begin(), B.end());

    bool break_flag = false;
    rep(i, 1, M) {

        int query = B[i];

        while (!A_que.empty() && query > A_que.top()) {
            A_que.pop();
        }
        // cout << A_que.top() << " " << query << endl;
        if (A_que.empty()) {
            // cout << "query";
            break_flag = true;
            break;
        }

        if (A_que.top() != query) {
            // cout << "query";
            break_flag = true;
            break;
        }
        A_que.pop();
    }
    if (break_flag) {
        cout << "No";
    } else {
        cout << "Yes";
    }
}