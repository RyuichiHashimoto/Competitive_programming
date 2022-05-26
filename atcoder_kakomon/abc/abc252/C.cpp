#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

typedef long long ll;
#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;


const int MAX_E = 3001;


typedef pair<int, int> P;
int pow(int x, int n) {


    int ret = 1;
    while (n > 0) {
        if (n & 1 == 1) {
            ret = (ret * x);
        }
        x = (x * x);

        n = n >> 1;
    }
    return ret;
}

int main() {


    int N;
    cin >> N;
    vector<string> name(N);

    rep(i, 1, N) {
        cin >> name[i - 1];
    }

    vector<int> ans(10);

    int total_ans = 100000000;
    rep(i, 0, 9) {
        vector<int> count(10);
        // map<int, int> count;
        int max_val = -1;
        rep(j, 0, N - 1) {

            // cout << name[j] << endl;

            int idx = name[j].find(i + '0');

            int tmp = -1;
            if (count[idx] == 0) {
                tmp = idx;
            } else {
                int additional = 10 * count[idx];
                tmp = idx + additional;
            }
            max_val = max(max_val, tmp);
            count[idx]++;
            // cout << i << " " << max_val << endl;
        }
        total_ans = min(total_ans, max_val);
    }
    cout << total_ans;
}