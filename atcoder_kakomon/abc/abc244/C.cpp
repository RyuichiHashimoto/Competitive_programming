#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 1.0E5;
const ll LL_MAX = 0x7FFFFFFFFFFFFFFF;

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
#define brep(i, num) for (int i = 0; i < (int)(1 << num); i++)

typedef pair<int, int> P;


int main(void) {

    int N;

    cin >> N;

    bool used[3000];

    fill(used, used + 3000, false);

    int hand = 1;
    int other_hand = -1;

    while (true) {
        while (used[hand]) hand++;
        cout << hand << endl;
        used[hand] = true;

        cin >> other_hand;

        if (other_hand == 0) {
            break;
        }
        used[other_hand] = true;
    }

    return 0;
}
