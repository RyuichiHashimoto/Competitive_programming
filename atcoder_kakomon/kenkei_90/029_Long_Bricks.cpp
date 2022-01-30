#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)




namespace segment_tree
{

    typedef long long ll;

    class segment_tree_for_maximum
    {

    private:
        vector<ll> dat;   //segment tree本体
        vector<ll> cache; // キャッシュ

        int n_leafs; //最終ノードの数 (完全２部木のため、n_leafsは2の累乗個作成し)
        int n_data;  // データ数
        const ll WORST_VALUE = 0x8000000000000000;

        ll compare(ll a, ll b)
        {
            return max(a, b);
        }

        /*            
            キャッシュの情報をk番目のノードに代入する。
            代入後、k番目のキャッシュ情報は削除するため、そのキャッシュ情報を子ノードに伝達する。
        */
        void push(int k)
        {

            // 葉以外のノードを指定した場合、
            if (k < n_leafs)
            {
                cache[2 * k + 1] = compare(cache[k], cache[k * 2 + 1]);
                cache[2 * k + 2] = compare(cache[k], cache[k * 2 + 2]);
            }
            dat[k] = compare(cache[k], dat[k]);
            cache[k] = 0;
        }

        /*
                [left, right)の範囲を値xで塗り替える。
                
            */
        void __update(int left, int right, ll x, int k, int l, int r)
        {
            push(k);

            //更新範囲にかすってもいない場合、何もしない。
            if (r <= left || right <= l)
            {
                return;
            }

            //現在見ている範囲[l, r]が更新範囲を完全に覆っている場合
            if (left <= l && r <= right)
            {
                cache[k] = x;
                push(k);
                return;
            }

            __update(left, right, x, 2 * k + 1, l, (l + r) >> 1);
            __update(left, right, x, 2 * k + 2, (l + r) >> 1, r);
            dat[k] = compare(dat[k * 2 + 1], dat[2 * k + 2]);
        }

        /*
            完全2部木のルートノードから順に見て、[left, right)の範囲で最良値を求める。
                
            k：節点の番号
            [l , r): その節点を見ている範囲
        */
        ll __query(int left, int right, int k, int l, int r)
        {
            push(k);
            if (left >= r || right <= l)
            {
                return WORST_VALUE;
            }
            if (left <= l && r <= right)
            {
                return dat[k];
            }
            else
            {
                ll vl = __query(left, right, k * 2 + 1, l, (l + r) >> 1);
                ll vr = __query(left, right, k * 2 + 2, (l + r) >> 1, r);
                return compare(vl, vr);
            }
        }

    public:
        segment_tree_for_maximum(int N)
        {

            n_leafs = 1;
            n_data = N;

            while (n_leafs < n_data)
            {
                n_leafs *= 2;
            }
            dat.resize(2 * n_leafs);
            cache.resize(2 * n_leafs);
        }

        /*
                [left,right)の最良値を返す。
            */
        ll query(int left, int right)
        {
            return __query(left, right, 0, 0, n_leafs);
        }
        /*
                [left,right)の要素をxにする。
            */
        void update(int left, int right, ll x)
        {
            return __update(left, right, x, 0, 0, n_leafs);
        }
    };
}

int main(void)
{
    int W,N;
    cin >> W >> N;

    segment_tree::segment_tree_for_maximum tree(W);

    // cout << N << endl;
    rep(i, N)
    {
        int L, R;
        cin >> L >> R;

        int height = tree.query(L, R+1) + 1;
        tree.update(L, R+1, height);
        cout << height << endl;
        
    }
    // cout << " " << endl;

}