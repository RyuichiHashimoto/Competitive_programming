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

    int N;
    cin >> N;
    vector<int> array(N);

    rep(i, 0, N - 1) {
        cin >> array[i];
    }

    int minimum = *min_element(array.begin(), array.end());

    rep(i, 0, N - 1) {
        array[i] -= minimum;
    }
    


}