
#include <bits/stdc++.h>

#include <cmath>
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

    int result = 0;
    while (true) {
        int a;
        cin >> a;
        if (a == 0) {
            break;
        }

        vector<list<int>> puyo(5);
        rep(i, 1, a) {
            rep(j, 1, 5) {
                int tmp = -1;
                cin >> tmp;
                puyo[j - 1].push_back(tmp);
            }
        }


        int end_flag = 0;
        bool break_flag = true;

        while (break_flag) {
            break_flag = false;
            vector<list<int>::iterator> itera(5);
            rep(i, 0, 4) {
                itera[i] = puyo[i].begin();
            }

            while (end_flag != 5) {
                vector<int> last_val(5);
                int end_flag_counter = 0;
                rep(i, 0, 4) {
                    if (itera[i] == puyo[i].end()) {
                        end_flag_counter++;
                        last_val[i] = -1 * (i + 1);
                    } else {
                        last_val[i] = *itera[i];
                    }
                }

                if (end_flag_counter >= 3) {
                    break;
                }
                int from, to;

                int j, k;
                for (j = 0; j < 3; j++) {
                    for (k = j + 1; k < 5; k++) {
                        if (last_val[j] != last_val[k]) {
                            break;
                        }
                    }
                    if (to - from < k - 1 - j) {
                        from = j;
                        to = k - 1;
                    }
                }

                if (to - from >= 2) {
                    result += (to - from + 1) * (last_val[from]);
                    rep(k, 0, 4) {
                        if ((from <= k) && (k <= to)) {
                            if (puyo[k].end() != itera[k]) {
                                break_flag = true;
                                itera[k] = puyo[k].erase(itera[k]);
                            }
                        } else {
                            if (puyo[k].end() != itera[k]) {
                                itera[k]++;
                            }
                        }
                    }
                } else {
                    rep(k, 0, 4) {
                        if (puyo[k].end() != itera[k]) {
                            itera[k]++;
                        }
                    }
                }
            }
        }
    }


    // break;
    cout << "ans:" << result << endl;
}