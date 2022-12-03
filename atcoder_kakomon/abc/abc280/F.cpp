#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>


#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
#define srep(i, from, to, step) for (ll i = from; i <= (ll)(to); i += step)
#define rrep(i, from, to) for (ll i = from; i >= (ll)(to); i--)
#define brep(i, n) for (ll i = 0; i < (1 << n); i++)
#define fore(i, a) for (auto& i : a)
#define all(x) (x).begin(), (x).end()
#define isOdd(a) a & 1
#define isEven(a) !(a & 1)
#define isContainMap(ma, val) ma.find(val) != ma.end()
#define displayVec(vec, delimiter)             \
    for (auto c : vec) cout << c << delimiter; \
    cout << endl;
#define setIntersection(a, b, result) set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(result, result.end()))

using namespace std;
typedef long long ll;


using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vp = vector<pair<ll, ll>>;

using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvs = vector<vector<string>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvp = vector<vector<pair<long long, long long>>>;

ll pow_ll(ll x, ll n) {


    ll ret = 1;
    while (n > 0) {
        if (n & 1 == 1) {
            ret = (ret * x);
        }
        x = (x * x);

        n = n >> 1;
    }
    return ret;
}

vi bit2array(int n, int n_bits) {
    vi ret(n_bits);
    int counter = 0;
    while (n > 0) {
        ret[counter++] = n & 1;
        n = n >> 1;
    }
    return ret;
}


class Edge {
  public:
    ll from;  // start of anEdge.
    ll to;    // end of anEdge.
    ll cap;   // the capacity for pass through
    ll cost;  // the cost to pass through (for finding the minimum cost flow)
    ll rev;   // the index of the inverseEdge.

    Edge(ll _from, ll _to, ll _cap, ll _cost, ll _rev) {
        from = _from;
        to = _to;
        cap = _cap;
        cost = _cost;
        rev = _rev;
    }
};

class Graph {
  public:
    vector<vector<Edge>> G;
    ll minimum_node_idx;
    ll maximum_node_idx;
    int n_vetrics;

    Graph(int n_of_vetrics) {
        G.resize(n_of_vetrics + 1);
        n_vetrics = n_of_vetrics;
        minimum_node_idx = 0x7FFFFFFF;
        maximum_node_idx = 0x80000000;
    }

    void add_Edge(Edge& x) {
        G[x.from].push_back(x);
        minimum_node_idx = min(minimum_node_idx, x.from);
        minimum_node_idx = min(minimum_node_idx, x.to);
        maximum_node_idx = max(maximum_node_idx, x.from);
        maximum_node_idx = max(maximum_node_idx, x.to);
    }

    int get_rank(int idx) {
        return G[idx].size();
    }
};


bool check(ll val, ll a, ll b, vector<ll>& A) {

    ll zouka_count = 0;
    ll gensho_count = 0;
    rep(i, 1, A.size()) {
        if (A[i - 1] > val) {
            zouka_count += (A[i - 1] - val) / b;
        } else if (A[i - 1] < val) {
            gensho_count += (val - A[i - 1] + a - 1ll) / a;
        }
    }

    if (zouka_count >= gensho_count) {
        return true;
    } else {
        return false;
    }

    // return true;
}


typedef pair<long long, long long> P;


vector<ll> divisor(ll number) {
    /*
        数字 numberの約数を小さい順に列挙
        計算量: sqrt(number);

    */
    vector<ll> res;

    for (ll i = 1; i * i <= number; i++) {

        if (number % i == 0) {
            res.push_back(i);
            if (i * i != number) {
                res.push_back(number / i);
            }
        }
    }
    return res;
}

typedef pair<long long, long long> P;
vector<P> prime_factor_as_vect(ll number) {
    // 素因数分解


    vector<P> ret;
    for (ll i = 2; i * i <= number; i++) {
        ll count = 0;
        while (number % i == 0) {
            count++;
            number = number / i;
        }
        if (count != 0) ret.push_back(P(i, count));
    }
    if (number != 1) ret.push_back(P(number, 1));
    return ret;
}

void solve_with_1(int N, int K, string& name, int start_1, int end_1) {

    int l = 1;
    int r = 1;
    int flag = 0;

    name += '0';
    name = '0' + name;
    N += 2;
    start_1++;
    end_1++;

    rep(i, 1, N) {
        char current = name[i - 1];
        char before = name[i - 2];
        bool current_1 = (current == '1' || current == '?');
        bool before_1 = (before == '1' || before == '?');
        if ((current_1) && (!before_1)) {
            l = i;
        } else if ((!current_1) && (before)) {
            r = i - 1;
            if ((start_1 >= l) && (end_1 <= r)) break;
        }
    }


    vector<char> msg;
    rep(i, l, r) {
        if ((i >= start_1) && (i <= end_1))
            msg.push_back('1');
        else
            msg.push_back(name[i - 1]);
    }

    int size_of_msg = msg.size();

    if (flag == 1) {
        cout << "No" << endl;
    } else if ((msg[0] == '1') && (msg[size_of_msg - 1] == '1')) {
        if (msg.size() == K) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (msg[0] == '1' || (msg[size_of_msg - 1] == '1')) {
        int size_of_1 = end_1 - start_1 + 1;

        if (msg.size() < K) {
            cout << "No" << endl;
        } else if (size_of_1 > K) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    } else {
        if (msg.size() == K) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

struct hoge {
    int a, b, c, d, e, f, g, h;
};

P calc_distance(P& base, P& from, P& to) {
    int x_dif = to.first - from.first;
    int y_dif = to.second - from.second;

    int one_dif1 = base.first - from.first;
    int one_dif2 = base.second - from.second;

    int two_dif1 = base.first - to.first;
    int two_dif2 = base.second - to.second;

    int yoko = one_dif1 * one_dif1 + one_dif2 * one_dif2;
    int tate = x_dif * x_dif + y_dif * y_dif;
    int shamen = two_dif1 * two_dif1 + two_dif2 * two_dif2;

    if (yoko != tate) {
        P ret{-1, -1};
        return ret;
    } else if ((yoko + tate) == shamen) {
        // cout << base.first << " " << base.second << " " << from.first << " " << from.second << " " << to.first << " " << to.second << " " << endl;
        // cout << base.first + x_dif << " " << base.second + y_dif << endl;
        P ret{base.first + x_dif, base.second + y_dif};
        return ret;
    } else {
        P ret{-1, -1};
        return ret;
    }
}

class Union_Find {
  private:
    int* par;
    int* rank;

  public:
    Union_Find(int size) {
        par = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    ~Union_Find() {
        delete par;
        delete rank;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            par[x] = root(par[x]);
            return par[x];
        }
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);

        par[y] = x;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};


void checkLoop(Graph& g, int from, int bef, vector<bool>& used, Union_Find& nakama) {

    for (auto e : g.G[from]) {
        nakama.unite(e.to, from);

        if (e.to == bef) continue;
        if (used[e.to]) continue;

        used[e.to] = true;
        checkLoop(g, e.to, from, used, nakama);
    }
}


map<ll, map<ll, ll>> accesssed;
map<ll, map<ll, ll>> dp_costs;
bool inf_flag = false;
ll dfs(Graph& g, int from, int origin, int target, ll val) {
    if (inf_flag) return 0ll;
    ll points_max = val;

    for (auto c : g.G[from]) {
        int to = c.to;
        ll point = c.cost;

        if (accesssed[origin][target]) {
            ll tmp = point + val;
            if (tmp != dp_costs[origin][target]) {
                inf_flag = true;
                return -1;
            }
        } else {
            points_max = max(dfs(g, to, origin, target, val + point) + point, points_max);
        }
    }

    accesssed[origin][target] = true;
    return dp_costs[origin][target] = points_max;
}

int main() {

    map<ll, map<ll, ll>> ma;
    map<ll, map<ll, ll>> used;

    int N, M, Q;
    cin >> N >> M >> Q;

    rep(i, 1, M) {
        ll A, B, C;
        cin >> A >> B >> C;

        if (used[A][B] == 0)
            ma[A][B] = C;
        else
            ma[A][B] = max(ma[A][B], C);

        if (used[B][A] == 0)
            ma[B][A] = -1 * C;
        else
            ma[B][A] = max(ma[B][A], -1ll * C);
        used[A][B] = true;
        used[B][A] = true;
    }

    Graph g(N + 1);

    rep(from, 1, N) {
        for (auto c : ma[from]) {
            ll to = c.first;
            ll cost = c.second;
            Edge e{from, to, 0, cost, 0};
            g.add_Edge(e);
        }
    }

    Union_Find ufw(100001);
    vector<bool> usedvec(100001);
    vector<bool> isLoop(100001);
    vector<bool> inf_flag_list(100001);

    rep(i, 1, N) checkLoop(g, i, -1, usedvec, ufw);

    rep(i, 1, Q) {
        int a, b;
        cin >> a >> b;

        if (ufw.root(a) != ufw.root(b)) {
            cout << "nan" << endl;
        } else if (inf_flag_list[ufw.root(a)]) {

        } else {
            inf_flag = false;


            ll cand = dfs(g, a, a, b, 0);
            // ll cand = -1;
            inf_flag_list[ufw.root(a)] = inf_flag;
            if (inf_flag) {
                cout << "inf" << endl;
            } else {
                cout << cand << endl;
            }
        }
    }
}
