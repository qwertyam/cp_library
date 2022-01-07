
// ----- LCA (begin) -----

#ifndef QWERTYAM_LCA_H 
#define QWERTYAM_LCA_H

#include <cassert>
#include <vector>

namespace qwertyam {

class LCA {
private:
	//number of vertices 
	std::size_t nv;

	// round up of logarithm of nv
	std::size_t log_nv;

	// dist_array[v] : distance from root to v 
	std::vector<int> dist_array; 

	// parent_array[n][v] : 2^n ancestors above vertex v (if none, then -1)
	std::vector<std::vector<int>> parent_array; 

	// make dist_array and parent_array
	void make_array(const int& now_vertex, const int& parent_vertex
		,const int& now_dist, const std::vector<std::vector<int>>& adjacency_list) {
		assert(0 <= now_vertex && now_vertex < (int) nv);
		dist_array[now_vertex] = now_dist;
		parent_array[0][now_vertex] = parent_vertex;
		for (int child_vertex : adjacency_list[now_vertex]) {
			if (child_vertex == parent_vertex) continue;
			make_array(child_vertex, now_vertex, now_dist + 1, adjacency_list);
		}
	}

public:
	LCA(const std::vector<std::vector<int>>& adjacency_list, const int& root_vertex) {
		nv = adjacency_list.size();
		log_nv = 1;
		while ((1 << log_nv) < (int) nv) log_nv++;
		dist_array = std::vector<int> (nv);
		parent_array = std::vector<std::vector<int>> (log_nv, std::vector<int> (nv, -1));
		make_array(root_vertex, -1, 0, adjacency_list);
		for (int i = 1; i < (int) log_nv; i++) {
			for (int j = 0; j < (int) nv; j++) {
				if (parent_array[i - 1][j] == -1) parent_array[i][j] = -1;
				else parent_array[i][j] = parent_array[i - 1][parent_array[i - 1][j]];
			}
		}
	}

	// find LCA of v1 and v2
	int query(int v1, int v2) {
		assert(0 <= v1 && v1 < (int) nv);
		assert(0 <= v2 && v2 < (int) nv);
		if (dist_array[v1] < dist_array[v2]) std::swap(v1, v2);
		for (int i = 0; i < (int) log_nv; i++) {
			assert(0 <= v1 && v1 < (int) nv);
			assert(0 <= v2 && v2 < (int) nv);
			if ((dist_array[v1] - dist_array[v2]) >> i & 1) {
				v1 = parent_array[i][v1];
			}
		}
		if (v1 == v2) return v1;
		for (int i = log_nv - 1; i >= 0; i--) {
			if (parent_array[i][v1] != parent_array[i][v2]) {
				v1 = parent_array[i][v1];
				v2 = parent_array[i][v2];
			}
		}
		return parent_array[0][v1];
	}
};

} // namespace qwertyam

#endif

// ----- LCA (end) -----

