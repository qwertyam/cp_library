
// ----- SparseTable (begin) -----

#ifndef SPARSE_TABLE_HPP
#define SPARSE_TABLE_HPP

#include <vector>
#include <cassert>

namespace qwertyam {

template <typename T>
class SparseTable {
private:
	int n;
	int log_n;
	std::vector<std::vector<T>> table;
	std::vector<int> log_table;
	T (*op) (T a, T b);

public:
	SparseTable(const std::vector<T>& vec, T (*_op) (T a, T b)) {
		n = vec.size();
		log_n = 0;
		while ((1 << log_n) <= n) log_n++;
		op = _op;
		table = std::vector<std::vector<T>> (log_n, std::vector<T> (n));
		for (int i = 0; i < n; i++) table[0][i] = vec[i];
		for (int i = 1; i < log_n; i++) {
			int len = (1 << i);
			for (int j = 0; j + len <= n; j++) {
				table[i][j] = op(table[i - 1][j], table[i - 1][j + len / 2]);
			}
		}
		log_table = std::vector<int> (n + 1);
		log_table[1] = 0;
		for (int i = 2; i <= n; i++) log_table[i] = log_table[i / 2] + 1;
	}

	T range_calc(const int& left, const int& right) const {
		assert(0 <= left && left < right && right <= n);
		int log_len = log_table[right - left];
		int len = (1 << log_len);
		return op(table[log_len][left], table[log_len][right - len]);
	}
};

} // namespace qwertyam

#endif

// ----- SparseTable (end) -----

