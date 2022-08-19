
// -------- LCS (begin) ---------
#ifndef QWERTYAM_LCS_HPP
#define QWERTYAM_LCS_HPP

#include <vector>
#include <string>

namespace qwertyam {

int LCS(const std::string& X, const std::string& Y) {
	const int len_x = X.size();
	const int len_y = Y.size();

	std::vector<std::vector<int>> dp(len_x + 1, std::vector<int> (len_y + 1, 0));
	for (int id_x = 1; id_x <= len_x; id_x++) {
		for (int id_y = 1; id_y <= len_y; id_y++) {
			dp[id_x][id_y] = dp[id_x - 1][id_y - 1] + (X[id_x - 1] == Y[id_y - 1]);
			dp[id_x][id_y] = std::max(dp[id_x][id_y], dp[id_x][id_y - 1]);
			dp[id_x][id_y] = std::max(dp[id_x][id_y], dp[id_x - 1][id_y]);
		}
	}

	return dp[len_x][len_y];
}

} // namespace qwerytam

#endif
// -------- LCS (end) ---------

