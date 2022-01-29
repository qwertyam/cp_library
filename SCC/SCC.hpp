
// ----- SCC (begin) -----
#ifndef SCC_HPP
#define SCC_HPP

#include <vector>
#include <algorithm>

namespace qwertyam {

class SCC {
private:
	// number of vertices
	int n;

	std::vector<int> tmp_v;

	std::vector<bool> used;

	std::vector<std::vector<int>> AdjacencyList;
	std::vector<std::vector<int>> RevAdjacencyList;

	std::vector<std::vector<int>> scc;

	void dfs_1(const int& now_v) {
		used[now_v] = true;
		for (int next_v : AdjacencyList[now_v]) {
			if (used[next_v] == false) dfs_1(next_v);
		}
		tmp_v.push_back(now_v);
	}

	void dfs_2(const int& now_v, std::vector<int>& vec) {
		vec.push_back(now_v);
		used[now_v] = true;
		for (int next_v : RevAdjacencyList[now_v]) {
			if (used[next_v] == false) dfs_2(next_v, vec);
		}
	}

public:
	explicit SCC (const std::vector<std::vector<int>>& _AdjacencyList) {
		n = _AdjacencyList.size();
		AdjacencyList = _AdjacencyList;
		used = std::vector<bool> (n, false);
		RevAdjacencyList = std::vector<std::vector<int>> (n);
		for (int i = 0; i < n; i++) {
			for (int j : AdjacencyList[i]) RevAdjacencyList[j].push_back(i);
		}
		for (int i = 0; i < n; i++) {
			if (used[i] == false) dfs_1(i);
		}
		std::reverse(tmp_v.begin(), tmp_v.end());
		for (int i = 0; i < n; i++) used[i] = false;
		for (int v : tmp_v) {
			if (used[v] == false) {
				std::vector<int> vec;
				dfs_2(v, vec);
				scc.push_back(vec);
			}
		}
	}

	std::vector<std::vector<int>> get_scc() const {
		return scc;
	}

	int scc_count() const {
		return scc.size();
	}
};

} // namespace qwertyam

#endif
// ----- SCC (end) -----

