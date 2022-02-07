#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

typedef pair<ll, ll> P;


/*
class RangeMax {
public:
	int size_ = 1;
	vector<long long> dat;

	void init(int sz) {
		while (size_ <= sz) size_ *= 2;
		dat.resize(size_ * 2, -(1LL << 60));
	}
	void update(int pos, long long x) {
		pos += size_;
		dat[pos] = x;
		while (pos >= 2) {
			pos >>= 1;
			dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
		}
	}
	long long query_(int l, int r, int a, int b, int u) {
		if (l <= a && b <= r) return dat[u];
		if (r <= a || b <= l) return -(1LL << 60);
		long long v1 = query_(l, r, a, (a + b) >> 1, u * 2);
		long long v2 = query_(l, r, (a + b) >> 1, b, u * 2 + 1);
		return max(v1, v2);
	}
	long long query(int l, int r) {
		return query_(l, r, 0, size_, 1);
	}
};

*/

namespace segment_tree{

    typedef long long ll;

    class range_max
    {

        private:
            vector<ll> dat;   //segment tree本体
            vector<ll> cache; // キャッシュ

            int n_leafs; //最終ノードの数 (完全２部木のため、n_leafsは2の累乗個作成し)
            int n_data;  // データ数
            const ll WORST_VALUE = -1;
            
            ll compare(ll a, ll b)
            {
                return max(a, b);
            }

            /*            
                キャッシュの情報をk番目のノードに代入する。
                キャッシュの情報をsegment treeに
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
                cache[k] = WORST_VALUE;
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
                if (r <= left || right <= l)
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
            void init(int N)
            {

                n_leafs = 1;
                n_data = N;

                while (n_leafs < n_data)
                {
                    n_leafs *= 2;
                }
                dat.resize(2 * n_leafs);
                cache.resize(2 * n_leafs);

                fill(dat.begin(),dat.end(),WORST_VALUE);
                fill(cache.begin(),cache.end(),WORST_VALUE);
            }

            range_max()
            {
                dat.clear();
                cache.clear();
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


const int MAX_W = 500+2;
const int MAX_N = 1E4+2;
typedef long long ll;
ll dp[MAX_N+1][MAX_W+1];

struct cooking{
    ll left,right,value;
};

int main(void)
{
    int N, W;
    cin >> W >> N;


    ll worst_value = -1;

    fill(dp[0], dp[N], worst_value);

    vector<cooking> ryori(N+1);

    rep(i,N){
        ll a,b, c;
        cin >> a >> b >> c;
        ryori[i] = cooking{a,b,c}; 
    }
    segment_tree::range_max segment[MAX_W ];

    rep(i,N){
        segment[i].init(W+2);                        
    }
    segment[0].update(ryori[0].left,ryori[0].right+1,ryori[0].value);    
    fill( dp[0] + ryori[0].left, dp[0] + (ryori[0].right + 1),ryori[0].value);
       
    for (int i = 1; i < N;i++){
        break;
        for (int j = 0; j <= W;j++){
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = 0; j <= W;j++){

            int cl = max(j - (int)ryori[i].right,0);
            int cr = max(j - (int)ryori[i].left+1,0);    

            if (cl == cr)
                continue;
            ll max_val = segment[i-1].query(cl,cr);
            // cout << max_val << " " << worst_value<<endl;
            if (max_val != worst_value){
                dp[i][j] = max(max_val + ryori[i].value,dp[i][j]);
            }
            segment[i].update(j,j+1,dp[i][j]);
        }        
      
    }
    rep(j,W){
        rep(i,N){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[N-1][W]<<endl;    
    
}
