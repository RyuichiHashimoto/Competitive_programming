
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
// typedef pair<int, int> P;
const int MAX_N = 1.0E5;
// const int INT_MAX = 0x7FFFFFFF;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define brep(i, num) for (ll i = 0; i < (ll)(1 << num); i++)


int parse(string &t) {


    int hour = (t[0] - '0') * 10 + (t[1] - '0');
    int min = (t[3] - '0') * 10 + (t[4] - '0');
    int second = (t[6] - '0') * 10 + (t[7] - '0');


    return 3600 * hour + 60 * min + second;
}

int main(void) {

    int n;

    int ruiseki[86402];
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }


        fill(ruiseki, ruiseki + 86402, 0);


        rep(i, 1, n) {
            string from, to;
            cin >> from >> to;
            ruiseki[parse(from)]++;
            ruiseki[parse(to)]--;
        }

        int ret = ruiseki[0];

        rep(i, 1, 86400) {
            ruiseki[i] += ruiseki[i - 1];
            ret = max(ret, ruiseki[i]);
        }
        string b = "03:00:00";
        cout << ret << endl;
    }

    vector<ll> kosa(1000002);
}
