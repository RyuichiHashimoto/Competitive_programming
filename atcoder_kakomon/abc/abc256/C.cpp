#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>

typedef long long ll;
#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)

using namespace std;


int main() {

    int h1, h2, h3, w1, w2, w3;

    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;


    int counter = 0;
    rep(left_up, 1, 30) {
        rep(right_up, 1, 30) {
            rep(left_down, 1, 30) {
                rep(right_down, 1, 30) {

                    int migiue = h1 - (left_up + right_up);
                    int migi_mannaka = h2 - (left_down + right_down);

                    if (migiue <= 0) {
                        continue;
                    }

                    if (migi_mannaka <= 0) {
                        continue;
                    }

                    int migisita_1 = w3 - migi_mannaka - migiue;

                    int hidari_sita = w1 - (left_up + left_down);
                    int migi_man = w2 - (right_up + right_down);

                    int migisita_2 = h3 - hidari_sita - migi_man;

                    if (hidari_sita <= 0) {
                        continue;
                    }
                    if (migi_man <= 0) {
                        continue;
                    }
                    if (migisita_1 <= 0) {
                        continue;
                    }
                    if (migisita_2 <= 0) {
                        continue;
                    }
                    if (migisita_1 == migisita_2) {
                        counter++;
                    }
                }
            }
        }
    }
    cout << counter << endl;
}