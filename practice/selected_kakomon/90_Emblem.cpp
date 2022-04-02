
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<ll, ll> P;
const ll MAX_N = 1.0E5;
// const ll ll_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)

typedef pair<ll, ll> P;

int main(void) {


    int n, m;
    cin >> n >> m;

    vector<P> N_emb(n);
    vector<ll> N_dist(n);
    vector<P> M_emb(m);

    rep(i, 0, n - 1) {
        cin >> N_emb[i].first >> N_emb[i].second >> N_dist[i];
    }

    rep(i, 0, m - 1) {
        cin >> M_emb[i].first >> M_emb[i].second;
    }
    // return 0;
    double distance = 0;

    ll dist = 1000000000;
    rep(i, 0, n - 1) {
        dist = min(dist, N_dist[i]);
    }
    double min_ = dist;


    rep(i, 0, m - 1) {
        vector<double> dis(n + m);


        rep(j, 0, n - 1) {
            ll tmp = (M_emb[i].first - N_emb[j].first) * (M_emb[i].first - N_emb[j].first) +
                     (M_emb[i].second - N_emb[j].second) * (M_emb[i].second - N_emb[j].second);
            dis[j] = sqrt(tmp) - N_dist[j];
        }

        rep(j, 0, m - 1) {
            if (i == j) {
                dis[n + j] = 1000000000;
            } else {
                ll tmp = (M_emb[i].first - M_emb[j].first) * (M_emb[i].first - M_emb[j].first) +
                         (M_emb[i].second - M_emb[j].second) * (M_emb[i].second - M_emb[j].second);

                dis[n + j] = sqrt(tmp) / 2;
            }
        }


        min_ = min(min_, *min_element(dis.begin(), dis.end()));
    }
    cout << std::setprecision(10) << min_ << endl;
}
