#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;

int ctoi(char a) {
    return a - '0';
}

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;
typedef pair<ll, ll> P;

int main() {

    int K;
    string S;
    cin >> S >> K;

    int to = 0;
    int from = 0;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '.') {
            to++;
        }
        if (to == K + 1) {
            break;
        }
    }
    if (to < K) {
        cout << S.size() << endl;
        return 0;
    }
    // cout << to << endl;
    cout << from << " " << to << endl;


    int origin_to = to;
    int origin_from = from;
    int ret = to - from + 1;
    while (true) {

        int f_counter = 0;
        int to_counter = 0;

        int counter = 0;
        for (f_counter = 1; f_counter + from < S.size(); f_counter++) {
            if (S[f_counter + from] == '.') {
                counter++;
                if (counter == 1) {
                    break;
                }
            }
        }

        counter = 0;
        for (to_counter = 1; to_counter + to < S.size(); to_counter++) {
            if (S[to_counter + to] == '.') {
                counter++;
                if (counter == 2) {
                    break;
                }
            }
        }
        to_counter--;


        to = to + to_counter;
        from = from + f_counter;
        int tmp = to - from + 1;
        ret = max(ret, tmp);
        cout << from << " " << to << endl;
        // return 0;

        if (to == S.size() - 1) {
            break;
        }
    }
    cout << ret << endl;
}