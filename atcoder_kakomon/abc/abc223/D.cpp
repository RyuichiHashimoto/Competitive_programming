#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;
typedef long long ll;

const int MAX_E = 2E5 + 1;
vector<int> check[MAX_E];
vector<int> fo[MAX_E];
bool used[MAX_E];
int counter[MAX_E];

int main() {

    int N, M;
    cin >> N >> M;

    vector<int> A(M), B(M);


    fill(counter, counter + MAX_E, 0);
    fill(used, used + MAX_E, false);

    rep(i, 1, M) {
        cin >> A[i - 1] >> B[i - 1];
        check[B[i - 1]].push_back(A[i - 1]);
        fo[A[i - 1]].push_back(B[i - 1]);
    }
    priority_queue<int, vector<int>, greater<int>> que;

    rep(i, 1, N) {
        if (check[i].empty()) {
            que.push(i);
            used[i] = true;
        }
    }

    vector<int> output;

    while (!que.empty()) {
        int val = que.top();
        que.pop();

        output.push_back(val);

        for (auto c : fo[val]) {
            counter[c]++;

            if (counter[c] == check[c].size()) {
                if (!used[c]) {
                    que.push(c);
                    used[c] = true;
                }
            }
        }
    }
    if (output.size() == N) {
        for (auto c : output) {
            cout << c << " ";
        }
        cout << endl;
    } else {
        cout << "-1";
    }

    //  return 1;
}