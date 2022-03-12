#include <bits/stdc++.h>

#include <iostream>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)


typedef long long ll;

typedef pair<int, int> P;

struct human {
    int x, y;
    char vec;

    bool operator<(const human& right) const {
        if (vec != right.vec) {
            return vec == 'R';
        } else if (x != right.x) {
            return x < right.x;
        } else {
            return 1;
        }
    }
};

int main(void) {

    int N;

    cin >> N;


    map<int, vector<human>> map_;

    vector<int> X(N);
    vector<int> Y(N);

    rep(i, 1, N) {
        cin >> X[i - 1] >> Y[i - 1];
    }
    string val;
    cin >> val;

    rep(i, 0, N - 1) {
        map_[Y[i]].push_back(human{X[i], Y[i], val[i]});
    }

    for (auto key : map_) {
        sort(key.second.begin(), key.second.end());
        if (key.second.size() == 1) {
            continue;
        } else if (key.second[0].vec == key.second[key.second.size() - 1].vec) {
            continue;
        } else if (key.second[0].x < key.second[key.second.size() - 1].x) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}