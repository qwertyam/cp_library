
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
template <typename T> void chmax(T& a, T b) {a = std::max(a, b);}
template <typename T> void chmin(T& a, T b) {a = std::min(a, b);}
long long pwmd(const long long& a, const long long& n) {
	if (n == 0) return 1LL;
	long long tmp = pwmd(a, n / 2);
	tmp = tmp * tmp % MOD;
	if (n % 2 == 1) tmp = tmp * a % MOD;
	return tmp;
}

struct MAIN {
private:
public:
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


