#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;


int main(void) {

    int N;

    cin >> N;

    vector<P> town(N + 1);

    rep(i, 0, N - 1) {
        cin >> town[i].first >> town[i].second;
    }

    vector<int> perm(N);

    rep(i, 0, N - 1) {
        perm[i] = i;
    }

    double distance = 0;
    int count = 0;
    do {
        count++;
        double tmp_distance = 0;

        rep(i, 1, N - 1) {
            int x_dif = (town[perm[i]].first - town[perm[i - 1]].first) * (town[perm[i]].first - town[perm[i - 1]].first);
            int y_dif = (town[perm[i]].second - town[perm[i - 1]].second) * (town[perm[i]].second - town[perm[i - 1]].second);
            // cout << x_dif << " " << y_dif << endl;

            tmp_distance += sqrt(x_dif + y_dif);
        };
        distance += tmp_distance;
    } while (next_permutation(perm.begin(), perm.end()));


    cout << setprecision(10) << distance / count << endl;
}