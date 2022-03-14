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

    int Distance, n_tempo, n_order;
    cin >> Distance >> n_tempo >> n_order;
    vector<int> tempo(n_tempo + 1);
    tempo[0] = 0;

    rep(i, 1, n_tempo - 1) {
        cin >> tempo[i];
    }

    tempo[n_tempo] = Distance;

    sort(tempo.begin(), tempo.end());
    rep(i, 0, n_tempo + 1 - 1) {
        // cout << tempo[i] << " ";
    }
    // cout << endl;

    int dist = 0;
    int pos;
    rep(i, 1, n_order) {
        cin >> pos;
        auto a = lower_bound(tempo.begin(), tempo.end(), pos);

        int ue = *a;
        int sita = *(a - 1);

        dist += min(ue - pos, pos - sita);

        // cout << pos << " " << *a << " " << *(a - 1) << endl;
    }
    cout << dist << endl;
}