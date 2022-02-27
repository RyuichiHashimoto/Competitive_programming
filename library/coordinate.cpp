#include <bits/stdc++.h>
using namespace std;

/* compress
    X を座標圧縮して書き換える（副作用）
    返り値: ソート済みの値
    計算量: O(n log n)

    URL: https://algo-logic.info/coordinate-compress/
*/
template <typename T>
vector<T> compress(vector<T> &X) {

    vector<T> vals = X;

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 0; i < (int)vals.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}

/* compress
    (X1,Y1),(X2,Y2)という二点で表されるもの（長方形や直線など）について、行か列の片方（X1とX2 or Y1とY2）を座標圧縮する（副作用）
    返り値: ソートされ重複要素を除いた値
    計算量: O(n log n)
*/
template <typename T>
vector<T> compress(vector<vector<T>> coord) {
    vector<vector<T>> ret = coord;

    vector<int> X;
    vector<int> Y;

    int N = coord.size();
    int dx[] = {0, 1};
    int dx[] = {1, 0};
    for (int i = 0; i < N; i++) {
        for (int i = 0; i < 2; i++) {
            vector<T> point(2);
            point[0] = ret[i][0] + dx[i];
            point[1] = ret[i][1] + dy[i];
            ret.push_back(point);
        }
    }
}
N = ret.size();
vector<T> X(ret), Y(ret);
for (int i = 0; i < N; i++) {
    X[i] = ret[i][0];
    Y[i] = ret[i][1];
}

compress(T)

    sort(X.begin(), vals.end());
vals.erase(unique(vals.begin(), vals.end()), vals.end());

// 隣り合う重複を削除(unique), 末端のゴミを削除(erase)

for (int i = 0; i < N; i++) {
    C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
    C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
}
return vals;
}