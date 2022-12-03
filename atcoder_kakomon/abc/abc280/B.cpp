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

namespace mod {
    constexpr long long safe_mod(long long x, long long m) {
        x %= m;
        if (x < 0) x += m;
        return x;
    }

    // @param b `1 <= b`
    // @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
    constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
        a = safe_mod(a, b);
        if (a == 0) return {b, 0};

        // Contracts:
        // [1] s - m0 * a = 0 (mod b)
        // [2] t - m1 * a = 0 (mod b)
        // [3] s * |m1| + t * |m0| <= b
        long long s = b, t = a;
        long long m0 = 0, m1 = 1;

        while (t) {
            long long u = s / t;
            s -= t * u;
            m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

            // [3]:
            // (s - t * u) * |m1| + t * |m0 - m1 * u|
            // <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
            // = s * |m1| + t * |m0| <= b

            auto tmp = s;
            s = t;
            t = tmp;
            tmp = m0;
            m0 = m1;
            m1 = tmp;
        }
        // by [3]: |m0| <= b/g
        // by g != b: |m0| < b/g
        if (m0 < 0) m0 += b / s;
        return {s, m0};
    }


    template <std::uint_fast64_t Modulus>
    class modint {
      private:
        using u64 = std::uint_fast64_t;
        u64 value;

      public:
        constexpr modint(const u64 x = 0) noexcept {

            if (Modulus != 998244353 and Modulus != 1000000007) {
                std::cerr << "unexpected Module: " << Modulus << std::endl;
                exit(-1);
            }
            value = x % Modulus;
        }


        constexpr modint operator+=(const modint rhs) noexcept {
            this->value += rhs.val();
            if (this->value >= Modulus) {
                this->value -= Modulus;
            }

            return *this;
        }

        constexpr modint operator-=(const modint rhs) noexcept {
            if (this->value < rhs.val()) {
                this->value += Modulus;
            }
            this->value -= rhs.val();
            return *this;
        }

        constexpr modint operator*=(const modint rhs) noexcept {
            this->value = this->value * rhs.val();
            if (this->value >= Modulus) {
                this->value = this->value % Modulus;
            }
            return *this;
        }

        constexpr modint operator/=(const modint& rhs) {
            return *this = (*this) * rhs.inv();
        }


        constexpr modint operator+(const modint rhs) const noexcept {
            return modint(*this) += rhs;
        }

        constexpr modint operator-(const modint rhs) const noexcept {
            return modint(*this) -= rhs;
        }

        constexpr modint operator*(const modint rhs) const noexcept {
            return modint(*this) *= rhs;
        }

        constexpr modint operator/(const modint rhs) const noexcept {
            return modint(*this) /= rhs;
        }

        friend bool operator==(const modint& lhs, const modint& rhs) {
            return lhs.value == rhs.value;
        }
        friend bool operator!=(const modint& lhs, const modint& rhs) {
            return lhs.value != rhs.value;
        }
        friend bool operator<(const modint& lhs, const modint& rhs) {
            return lhs.value < rhs.value;
        }
        friend bool operator>(const modint& lhs, const modint& rhs) {
            return lhs.value > rhs.value;
        }
        friend bool operator>=(const modint& lhs, const modint& rhs) {
            return lhs.value >= rhs.value;
        }
        friend bool operator<=(const modint& lhs, const modint& rhs) {
            return lhs.value <= rhs.value;
        }

        friend std::ostream& operator<<(std::ostream& out, const modint& f) {
            return out << f.value;
        }


        u64 val() const {
            return this->value;
        }

        unsigned long long ull() const {
            return (unsigned long long)this->value;
        }

        long long ll() const {
            return (long long)this->value;
        }


        modint pow(long long n) const {
            assert(0 <= n);
            modint x = *this, r = 1;
            while (n) {
                if (n & 1) r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }

        modint inv() const {
            auto eg = inv_gcd(value, Modulus);
            assert(eg.first == 1);
            return eg.second;
        }
    };
}  // namespace mod

// using mint = mod::modint<998244353>;
using mint = mod::modint<1000000007>;

double dfs(int N) {

    if (N == 1) {
        return 3.5;
    }

    double min_val = dfs(N - 1);

    double ret_val = 0;
    rep(i, 1, 6) {
        ret_val += (double)1 / 6 * (max(min_val, (double)i));
    }
    return ret_val;
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

namespace segtree {

    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }

    template <class S, S (*op)(S, S), S (*e)()>
    struct segtree {
      private:
        int _n, size, log;
        std::vector<S> d;
        void update(int k) {
            d[k] = op(d[2 * k], d[2 * k + 1]);
        }

      public:
        segtree() : segtree(0) {
        }
        explicit segtree(int n) : segtree(std::vector<S>(n, e())){};
        explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
            log = ceil_pow2(_n);
            size = 1 << log;

            d = std::vector<S>(2 * size, e());
            for (int i = 0; i < _n; i++) d[size + i] = v[i];
            for (int i = size - 1; i >= 1; i--) {
                update(i);
            }
        }

        void set(int p, S x) {
            assert(0 <= p && p < _n);
            p += size;
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }

        S get(int p) {
            assert(0 <= p && p < _n);
            return d[p + size];
        }

        // [l, r)
        S prod(int l, int r) const {
            assert(0 <= l && l <= r && r <= _n);
            S sml = e(), smr = e();
            l += size;
            r += size;

            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }
            return op(sml, smr);
        }
        S all_prod() const {
            return d[1];
        }
    };

}  // namespace segtree

ll e() {
    return (1ll << 31) - 1ll;
}
ll min_(ll A, ll B) {
    return min(A, B);
}

int main() {

    int N;
    cin >> N;

    vl S(N), A(N);
    rep(i, 1, N) {
        cin >> S[i - 1];
    }

    A[0] = S[0];

    rep(i, 1, N - 1) {
        A[i] = S[i] - S[i - 1];
    }
    for (auto c : A) {
        cout << c << " ";
    }
    cout << endl;
}
