#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;
typedef long long ll;

const int MAX_E = 3001;
typedef pair<int, int> P;


int main() {

    int N, K;

    cin >> N >> K;

    vector<bool> used(N);

    vector<int> A_list(K);
    vector<int> not_A_list;

    rep(i, 0, K - 1) {
        cin >> A_list[i];
        A_list[i]--;
        used[A_list[i]] = true;
    }

    vector<double> X(N), Y(N);
    rep(i, 0, N - 1) {
        cin >> X[i] >> Y[i];
        if (!used[i]) {
            not_A_list.push_back(i);
        }
    }


    double max_dinstance = -1;
    for (auto c : not_A_list) {
        double min_distance = 10000000;
        for (auto d : A_list) {
            double distance = (X[c] - X[d]) * (X[c] - X[d]) + (Y[c] - Y[d]) * (Y[c] - Y[d]);
            distance = sqrt(distance);
            if (min_distance > distance) {
                min_distance = distance;
            }
        }
        if (max_dinstance < min_distance) {
            max_dinstance = min_distance;
        }
    }
    cout << std::setprecision(10) << max_dinstance << endl;
}