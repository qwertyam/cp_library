

#include <bits/stdc++.h>

namespace qwertyam {

int d4r[] = {0, 1, 0, -1};
int d4c[] = {1, 0, -1, 0};
int d8r[] = {1, 1, 0, -1, -1, -1, 0, 1};
int d8c[] = {0, 1, 1, 1, 0, -1, -1, -1};
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int INF = 1001001001;
constexpr long long LINF = 1001002003004005006;
constexpr char endl = '\n';
template <typename T> void chmax(T& a, const T& b);
template <typename T> void chmin(T& a, const T& b);
long long pwmd(const long long& a, const long long& n);
long long gcd(const long long& a, const long long& b);
long long lcm(const long long& a, const long long& b);


struct MAIN {
	void main() {
		return;
	}
};
} // namespace qwertyam


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int test_case = 1;
	// std::cin >> test_case;
	while (test_case--) {
		qwertyam::MAIN main_;
		main_.main();
	}
	return 0;
}

// -----------------------------------------------

namespace qwertyam {

template <typename T> 
void chmax(T& a, const T& b) {
	a = std::max(a, b);
	return;
}

template <typename T>
void chmin(T& a, const T& b) {
	a = std::min(a, b);
	return;
}

long long pwmd(const long long& a, const long long& n) {
	if (n == 0) return 1LL;
	long long tmp = pwmd(a, n / 2);
	tmp = tmp * tmp % MOD;
	if (n % 2 == 1) tmp = tmp * a % MOD;
	return tmp;
}

long long gcd(const long long& a, const long long& b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

long long lcm(const long long& a, const long long& b) {
	return a / gcd(a, b) * b;
}

} // namespace qwertyam

