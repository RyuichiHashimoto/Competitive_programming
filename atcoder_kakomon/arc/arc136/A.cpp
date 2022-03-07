#include <bits/stdc++.h>

#include <iostream>
#include <set>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
typedef long long ll;


int main(void) {

    int N;
    cin >> N;
    string name;
    cin >> name;


    deque<char> que;
    deque<char> answer;
    rep(i, 1, N) {
        que.push_back(name[i - 1]);
    }

    char current = 'D', before = 'D';
    string s = "";

    while (!que.empty()) {

        if (answer.empty()) {
            before = 'D';
        } else {
            before = answer.back();
        }

        current = que.front();
        que.pop_front();

        if (before == 'B' && current == 'B') {
            // cout << "No" << endl;
            que.push_front('A');
            answer.pop_back();
        } else if (before == 'B' && current == 'A') {
            que.push_front('B');
            que.push_front('A');
            answer.pop_back();
        } else {
            answer.push_back(current);
        }
    }

    while (!answer.empty()) {
        cout << answer.front();
        answer.pop_front();
    }
}