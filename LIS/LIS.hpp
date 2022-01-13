
// ----- LIS (begin) -----

#ifndef QWERTYAM_LIS_HPP
#define QWERTYAM_LIS_HPP

#include <cassert>
#include <vector>
#include <limits>
#include <algorithm>

namespace qwertyam {

template <typename T> 
class LIS {
private:
	// size of vec
	int sz;

	// dp[i]: the mimimum of the last-most values of the LIS whose length is i
	std::vector<T> dp;

	// id[i]: index of vec[i] in array dp 
	std::vector<int> id;

	// LIS 
	std::vector<T> lis;

public:
	LIS(const std::vector<T>& vec, const bool& strict = true) {
		sz = vec.size();
		T MAX_T = std::numeric_limits<T>::max();
		T MIN_T = std::numeric_limits<T>::min();
		dp = std::vector<T> (sz + 1, MAX_T);
		dp[0] = MIN_T;
		id  = std::vector<int> (sz);
		for (int i = 0; i < sz; i++) {
			int index;
			if (strict) index = std::lower_bound(dp.begin(), dp.end(), vec[i]) - dp.begin();
			else index = std::upper_bound(dp.begin(), dp.end(), vec[i]) - dp.begin();
			dp[index] = vec[i];
			id[i] = index;
		}
		int max_index = std::max_element(id.begin(), id.end()) - id.begin();
		int tmp = id[max_index];
		for (int i = max_index; i >= 0; i--) {
			if (id[i] == tmp) {
				lis.push_back(vec[i]);
				tmp--;
			}
		}
		std::reverse(lis.begin(), lis.end());
	}

	// get LIS
	std::vector<T> get_lis() const {
		return lis;
	}

	// get the length of LIS
	int get_len() const {
		return (int) lis.size();
	}
};

} // namespace qwertyam

#endif

// ----- LIS (end) -----

