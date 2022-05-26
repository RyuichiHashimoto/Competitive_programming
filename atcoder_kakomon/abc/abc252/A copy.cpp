#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;
typedef long long ll;

const int MAX_E = 3001;


int main() {
    int N, K;
    string S;

    map<string, bool> check;

    cin >> N >> K;
    cin >> S;

    S = S + S;
    cout << endl;
    rep(i, 1, N) {
        if (N % i == 0) {
            int diff_count = 0;
            rep(j, 1, N / (i)-1) {
                rep(k, 0, i - 1) {
                    // cout << k << " " << i * j + k << endl;
                    if (S[k] != S[i * j + k]) {
                        diff_count++;
                    }
                }
            }

            if (diff_count <= K) {
                cout << i << endl;
                return 0;
            }
        } else {


            cout << "-----------" << i << "----------" << endl;


            rep(aa, 0, i) {
                int diff_count = 0;
                rep(j, 1, N / (i)) {
                    rep(k, 0, i - 1) {
                        if (i * j + k >= N) {
                            break;
                        }
                        cout << k << " " << i * j + k << endl;
                        if (S[k + aa] != S[i * j + k + aa]) {
                            diff_count++;
                        }
                    }
                }
                cout << "ans:" << diff_count << " " << i << endl;
                if (diff_count <= K) {
                    cout << i << endl;
                    return 0;
                }
            }
        }
    }

    cout << 0 << endl;
}