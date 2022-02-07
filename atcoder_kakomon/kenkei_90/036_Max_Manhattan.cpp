#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

typedef pair<ll, ll> P;

ll calc_manhattan(P point1, P point2){
    return abs(point1.first - point2.first) + abs(point2.second - point1.second);
}

int main(void)
{
    int N, Q;

    cin >> N >> Q;

    vector<P> zahyo(N);
    vector<P> rotated_zahyo(N);
    vector<ll> Querys(Q);

    P x_min{0x7FFFFFFFFFFFFFFF,-1}, x_max{-1,-1}, y_min{0x7FFFFFFFFFFFFFFF,-1}, y_max{-1,-1};

    rep(i, N)
    {
        ll a, b;
        cin >> a >> b;
        zahyo[i] = P{a, b};

        ll rotate_x = a + b;
        ll rotate_y = b - a;


        if (rotate_x > x_max.first){
            x_max.first = rotate_x;
            x_max.second = i;
        }

        if (rotate_x < x_min.first){
            x_min.first = rotate_x;
            x_min.second = i;
        }

        if (rotate_y > y_max.first)
        {
            y_max.first = rotate_y;
            y_max.second = i;
        }
        if (rotate_y < y_min.first)
        {
            y_min.first = rotate_y;
            y_min.second = i;
        }
    }


    rep(i, Q)
    {
        int q_id;
        cin >> q_id;
        q_id--;

        ll a = calc_manhattan(zahyo[x_max.second], zahyo[q_id]);
        ll b = calc_manhattan(zahyo[x_min.second], zahyo[q_id]);
        ll c = calc_manhattan(zahyo[y_max.second], zahyo[q_id]);
        ll d = calc_manhattan(zahyo[y_min.second], zahyo[q_id]);
        cout << max({a, b, c, d}) << endl;
    }
}