#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <set>
#include <string>
typedef long long ll;
#define rep(i, from, to) for (ll i = from; i <= (ll)(to); i++)
using namespace std;


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