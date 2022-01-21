
// ----- SegTree (begin) -----
#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include <cassert>
#include <vector>

namespace qwertyam {
template <typename T>
class SegTree {
private:
	T (*op) (T a, T b);
	T e;
	std::vector<T> tree;

	// length of input array
	int n;

	// power of 2 which is equal or more than n
	int n2;

	// log n2
	int log;

public:
	SegTree (const std::vector<T> &vec, T (*_op) (T a, T b), const T& _e) {
		e = _e;
		op = _op;
		n = vec.size();
		n2 = 1;
		while (n2 < n) {
			n2 *= 2;
			log++;
		}
		tree = std::vector<T> (2 * n2, e);
		for (int i = 0; i < n; i++) tree[n2 + i] = vec[i];
		for (int i = n2 - 1; i > 0; i--) tree[i] = op(tree[2 * i], tree[2 * i + 1]);
	}

	void add(int index, const T& x) {
		assert(0 <= index && index < n);

		index += n2;
		tree[index] += x;
		while (index > 1) {
			index /= 2;
			tree[index] = op(tree[2 * index], tree[2 * index + 1]);
		}
	}

	void update(int index, const T& x) {
		assert(0 <= index && index < n);

		index += n2;
		tree[index] = x;
		while (index > 1) {
			index /= 2;
			tree[index] = op(tree[2 * index], tree[2 * index + 1]);
		}
	}

	T range_calc(int left, int right) const {
		assert(0 <= left && left < right && right <= n);

		left += n2;
		right += n2;
		T l_res = e;
		T r_res = e;
		while (left < right) {
			if (left % 2 == 0) left /= 2; 
			else {
				l_res = op(l_res, tree[left]);
				left = left / 2 + 1;
			}
			if (right % 2 == 0) right /= 2;
			else {
				r_res = op(tree[right - 1], r_res);
				right /= 2;
			}
		}
		return op(l_res, r_res);
	}

	T get(const int& index) const {
		assert(0 <= index && index < n);
		return tree[n2 + index];
	}
};
} // namespace qwertyam

#endif
// ----- SegTree (end) -----


