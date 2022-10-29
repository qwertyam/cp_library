
// ----- ModInt (begin) -----
#ifndef QWERTYAM_MODINT_HPP
#define QWERTYAM_MODINT_HPP

#include <iostream>
#include <vector>

namespace qwertyam {
template <int MOD>
class ModInt {
	using mint = ModInt<MOD>;

private:
	template <typename T>
	long long mod(const T& x) const {
		return (x % MOD + MOD) % MOD;
	}

	long long powmod(const long long& a, const long long& n) const {
		if (n == 0) return 1;
		long long res = powmod(a, n / 2);
		res = res * res % MOD;
		if (n % 2 == 1) res = res * a % MOD;
		return res;
	}

	mint inv() const {
		return powmod(val, MOD - 2);
	}

public:
	long long val;

	ModInt(): val(0) {}

	template <typename T>
	ModInt(const T& x) {
		val = mod(x);
	}

	mint pow(const long long& N) const {
		return mint(powmod(val, N));
	}

	void operator++() {
		val = mod(val + 1);
	}

	void operator++(int) {
		val = mod(val + 1);
	}

	void operator--() {
		val = mod(val - 1);
	}

	void operator--(int) {
		val = mod(val - 1);
	}

	void operator+=(const mint& x) {
		val = mod(val + x.val);
	}

	void operator-=(const mint& x) {
		val = mod(val - x.val);
	}

	void operator*=(const mint& x) {
		val = mod(val * x.val);
	}

	void operator/=(const mint& x) {
		val = mod((val * x.inv()).val);
	}

	mint operator+() const {
		return (*this);
	}

	mint operator-() const {
		return mint(0) - (*this);
	}

	friend mint operator+(const mint& x, const mint& y) {
		return mint(x.val + y.val);
	}

	friend mint operator-(const mint& x, const mint& y) {
		return mint(x.val - y.val);
	}

	friend mint operator*(const mint& x, const mint& y) {
		return mint(x.val * y.val);
	}

	friend mint operator/(const mint& x, const mint& y) {
		return mint(x.val * y.inv());
	}

	friend bool operator==(const mint& x, const mint& y) {
		return x.val == y.val;
	}

	friend bool operator!=(const mint& x, const mint& y) {
		return x.val != y.val;
	}
};
} // namespace qwertyam

#endif
// ----- ModInt (end) -----

