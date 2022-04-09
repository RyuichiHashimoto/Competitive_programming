
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF / 2ll;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)


ll dp[(1 << 17) + 1][17];
ll n_routes[(1 << 17) + 1][17];

ll tsp[17][17];
ll dist[17][17];


int main(void) {

    ll V, E;
    cin >> V >> E;
    fill(dp[0], dp[(1 << V) + 1], LL_MAX);
    fill(n_routes[0], n_routes[(1 << V) + 1], 0);
    fill(dist[0], dist[17], -1);
    fill(tsp[0], tsp[17], -1);

    rep(i, 1, E) {
        ll a, b, c, d = -1;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        tsp[a][b] = c;
        tsp[b][a] = c;

        dist[a][b] = d;
        dist[b][a] = d;
    }

    dp[0][0] = 0;
    n_routes[0][0] = 1;

    rep(S, 1, 1 << V) {

        rep(to, 0, V) {
            bool two = ((S >> to) & 1ll) == 1ll;
            if (!two) {
                continue;
            }

            rep(from, 0, V) {
                bool one = tsp[from][to] != -1ll;


                if (one) {
                    ll cost = dp[S ^ (1 << to)][from] + tsp[from][to];

                    if (dp[S][to] == cost) {
                        if (cost <= dist[from][to]) {
                            n_routes[S][to] += n_routes[S ^ (1 << to)][from];
                        }
                    } else if (dp[S][to] > cost) {

                        if (cost <= dist[from][to]) {
                            dp[S][to] = cost;
                            n_routes[S][to] = n_routes[S ^ (1 << to)][from];
                        }
                    }
                }
            }
        }
    }
    if ((n_routes[(1 << V) - 1][0] == 0) or (LL_MAX == dp[(1 << V) - 1][0])) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        // cout << "IMPOSSIBLE" << endl;
        cout << dp[(1 << V) - 1][0] << " " << n_routes[(1 << V) - 1][0] << endl;
    }
}
