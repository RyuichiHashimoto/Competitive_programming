#include <bits/stdc++.h>

#include <iostream>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

int main(void) {

    deque<int> que;

    int N;

    cin >> N;

    int tmp;
    int last_value = -1;
    int last_value_counter = 1;

    map<int, deque<int>> last_map;

    int second_last_value;
    int second_last_value_counter;


    rep(i, 1, N) {
        cin >> tmp;
        que.push_back(tmp);


        if (last_value == tmp) {
            last_value_counter++;
            // K 個連続した場合
            if (last_value_counter == last_value) {
                rep(j, 1, last_value) {
                    que.pop_back();
                }

                if (que.size() != 0) {
                    last_value = que.back();
                    last_value_counter = last_map[last_value].back();
                    last_map[last_value].pop_back();
                } else {
                    last_value = -1;
                    last_value_counter = 0;
                }
            }
        } else {
            last_map[last_value].push_back(last_value_counter);

            last_value_counter = 1;
            last_value = tmp;
        }
        cout << que.size() << endl;
    }
}