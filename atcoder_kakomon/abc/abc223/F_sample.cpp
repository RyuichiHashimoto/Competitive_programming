#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;

int ctoi(char a) {
    return a - '0';
}

#define rep(i, from, to) for (int i = from; i <= (int)(to); i++)

typedef long long ll;
typedef pair<ll, ll> P;

int counter = 0;


// 区間加算の区間和セグメントツリー
template <typename T>
class range_min_query {

  private:
    int n_leafs;
    int n_data;
    int n_nodes;
    vector<T> nodes;
    T inf = -1;


  public:
    // 1-indexed
    // array: {0, a1, a2, a3, a4, .., an};
    range_min_query(vector<ll> &array, T worst_val) {

        n_data = array.size();
        inf = worst_val;

        // 完全２部木のため、葉は2のべき乗数
        n_leafs = 1;


        do {
            n_leafs *= 2;
        } while (n_data > n_leafs);


        n_nodes = n_leafs * 2 - 1;

        nodes.resize(n_nodes + 1);
        fill(nodes.begin(), nodes.end(), inf);

        for (int i = 1; i < n_data; i++) {
            nodes[n_leafs + i - 1] = array[i];
        }
        for (int i = n_leafs - 1; i >= 1; i--) {
            nodes[i] = comparator(nodes[2 * i + 1], nodes[2 * i]);
        }
    }

    void update(int idx, T value) {
        idx += n_leafs - 1;
        nodes[idx] = value;

        while (idx > 1) {
            idx /= 2;
            nodes[idx] = comparator(nodes[2 * idx], nodes[2 * idx + 1]);
        }
    }

    void add(int idx, T value) {
        idx += n_leafs - 1;
        nodes[idx] += value;

        while (idx > 1) {
            idx /= 2;
            nodes[idx] = comparator(nodes[2 * idx], nodes[2 * idx + 1]);
        }
    }

    T comparator(T one, T two) {
        return min(one, two);
        // return min(one, two);
    }

    // [from, to]間で最適のものを抽出する。
    T query(int from, int to) {
        return __query(from, to, 1, 1, n_leafs);
    }


    T __query(int from, int to, int idx, int a, int b) {
        // 全く重なっていない場合
        if (from > b || to < a) {
            return inf;
        }

        // 完全に覆いかぶさっている場合
        if ((from < a) && (b < to)) {
            return nodes[idx];
        }

        if (a == b) {
            return nodes[idx];
        }


        T vl = __query(from, to, idx * 2, a, (a + b) / 2);
        T vr = __query(from, to, idx * 2 + 1, (a + b) / 2 + 1, b);
        return comparator(vl, vr);
    }

    void display_nodes() {
        for (auto s : nodes) {
            cout << s << " ";
        }
        cout << endl;
    }
};

int main() {

    int n, q;

    cin >> n >> q;

    ll inf = (1ll << 31) - 1ll;
    // ll inf = 0;

    vector<ll> arr(n, inf);
    range_min_query<ll> rmq(arr, inf);


    rep(i, 1, q) {
        ll com, x, y, z;
        cin >> com;


        if (com == 0) {
            cin >> x >> y;
            rmq.update(x + 1, y);
            // rmq.display_nodes();
        } else {
            cin >> x >> y;
            cout << rmq.query(x + 1, 1 + y) << endl;
        }
    }

    // cerr << "as";
    return 0;
}