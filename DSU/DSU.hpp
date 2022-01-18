
// ----- DSU (begin) -----

#ifndef QWERTYAM_DSU_HPP 
#define QWERTYAM_DSU_HPP 

#include <cassert>
#include <vector>
#include <utility>

namespace qwertyam {

class DSU {
private:
	// Number of whole elements
	int n;

	// Number of sets
	int ns;

	// size_or_parent[x]:
	// (-1) * (size of set).(if x is a leader of the set).
	// parent of x (otherwise).
	std::vector<int> size_or_parent;

public:
	explicit DSU(const int& N) {
		n = N;
		ns = N;
		size_or_parent = std::vector<int> (N, -1);
	}

	int leader(const int& x) {
		if (size_or_parent[x] < 0) return x;
		return size_or_parent[x] = leader(size_or_parent[x]);
	}

	bool merge(int x, int y) {
		assert(0 <= x && x < n);
		assert(0 <= y && y < n);
		x = leader(x);
		y = leader(y);
		if (x == y) return false;
		if (size_or_parent[x] > size_or_parent[y]) std::swap(x, y);
		size_or_parent[x] += size_or_parent[y];
		size_or_parent[y] = x;
		ns--;
		return true;
	}

	bool same(const int& x, const int& y) {
		assert(0 <= x && x < n);
		assert(0 <= y && y < n);
		return leader(x) == leader(y);
	}

	bool is_leader(const int& x) const {
		assert(0 <= x && x < n);
		return size_or_parent[x] < 0;
	}

	int set_count() const {
		return ns;
	}

	int size(const int& x) {
		assert(0 <= x && x < n);
		return -size_or_parent[leader(x)];
	}
};

} // namespace qwertyam

#endif
// ----- DSU (end) -----

