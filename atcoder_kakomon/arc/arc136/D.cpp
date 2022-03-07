#include <bits/stdc++.h>

#include <iostream>
#include <set>
using namespace std;


#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)
typedef long long ll;


struct query {
    int t, n, c;
};

int main(void) {

    string a, b;
    cin >> a >> b;

    string small_str, big_str;

    if (a.size() < b.size()) {
        small_str = a;
        big_str = b;
    } else {
        small_str = b;
        big_str = a;
    }

    map<int, int> big_counts;
    map<int, int> small_counts;

    rep(i, 0, big_str.size() - 1) {
        big_counts[big_str[i] - '0'] += 1;
    }
    rep(i, 0, small_str.size() - 1) {
        small_counts[small_str[i] - '0'] += 1;
    }

    string a_big_str = "", a_small_str = "";
    sort(small_str.begin(), small_str.end());
    // reverse(small_str.begin(), small_str.end());


    int counter = 0;

    rep(i, 0, small_str.size() - 1) {
        int s_c = small_str[i] - '0';
        cout << s_c << " " << big_counts[9 - s_c] << endl;

        if (counter == 0) {
            if (big_counts[10 - s_c] != 0) {
                big_counts[10 - s_c]--;
                small_counts[s_c]--;
                a_big_str += (10 - s_c) + '0';
                a_small_str += s_c + '0';
                counter++;
            }
        } else {
            if (big_counts[9 - s_c] != 0) {
                big_counts[9 - s_c]--;
                small_counts[s_c]--;
                a_big_str += (9 - s_c) + '0';
                a_small_str += s_c + '0';
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        a_small_str += string(small_counts[i], i + '0');
    }
    for (int i = 9; i >= 0; i--) {
        a_big_str += string(big_counts[i], i + '0');
    }
    reverse(a_small_str.begin(), a_small_str.end());
    reverse(a_big_str.begin(), a_big_str.end());

    if (a.size() < b.size()) {
        cout << a_small_str << endl;
        cout << a_big_str << endl;
    } else {
        cout << a_big_str << endl;
        cout << a_small_str << endl;
    }
}