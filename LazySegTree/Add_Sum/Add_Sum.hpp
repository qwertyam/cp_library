
// ----- LazySegTree [Add & Sum] (begin) -----

#ifndef QWERTYAM_LAZYSEGTREE_ADD_SUM_HPP
#define QWERTYAM_LAZYSEGTREE_ADD_SUM_HPP

#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

namespace qwertyam {

template <typename T>
class LazySegTree_Add_Sum {
private:
	// length of input array
	int n;

	// power of 2 which is equal or more than n
	int n2;

	// log n2
	int log;

	std::vector<T> val, lazy;

	void push(const int& k) {
		assert(0 <= k && k < 2 * n2);
		val[k] += lazy[k];
		if (k < n2) {
			lazy[2 * k] += lazy[k] / 2;
			lazy[2 * k + 1] += lazy[k] / 2;
		}
		lazy[k] = 0;
	}

	void update(const int& k) {
		assert(0 <= k && k < n2);
		push(2 * k);
		push(2 * k + 1);
		val[k] = val[2 * k] + val[2 * k + 1];
	}
public:
	explicit LazySegTree_Add_Sum(const std::vector<T>& vec) {
		n = vec.size();
		n2 = 1;
		log = 0;
		while (n2 < n) {
			n2 *= 2;
			log++;
		}
		val = std::vector<T> (2 * n2, 0);
		lazy = std::vector<T> (2 * n2, 0);
		for (int i = 0; i < n; i++) val[n2 + i] = vec[i];
		for (int i = n2 - 1; i > 0; i--) update(i);
	}

	void range_add(int left, int right, T x) {
		assert(0 <= left && left < right && right <= n);
		left += n2;
		right += n2;
		for (int i = log; i > 0; i--) {
			if (((left >> i) << i) != left) push(left >> i);
			if (((right >> i) << i) != right) push(right >> i);
		}
		int left2 = left;
		int right2 = right;
		int two = 1;
		while (left2 < right2) {
			if (left2 % 2 == 0) left2 /= 2;
			else {
				lazy[left2] += x * two;
				left2 = left2 / 2 + 1;
			}
			if (right2 % 2 == 0) right2 /= 2;
			else {
				lazy[right2 - 1] += x * two;
				right2 /= 2;
			}
			two *= 2;
		}
		for (int i = 1; i <= log; i++) {
			if (((left >> i) << i) != left) update(left >> i);
			if (((right >> i) << i) != right) update(right >> i);
		}
	}

	T range_sum(int left, int right) {
		assert(0 <= left && left < right && right <= n);
		left += n2;
		right += n2;
		for (int i = log; i > 0; i--) {
			if (((left >> i) << i) != left) push(left >> i);
			if (((right >> i) << i) != right) push(right >> i);
		}
		T l_res = 0;
		T r_res = 0;
		while (left < right) {
			if (left % 2 == 0) left /= 2;
			else {
				push(left);
				l_res = l_res + val[left];
				left = left / 2 + 1;
			}
			if (right % 2 == 0) right /= 2; 
			else {
				push(right - 1);
				r_res = val[right - 1] + r_res;
				right /= 2;
			}
		}
		return l_res + r_res;
	}

	T get(const int& index) {
		assert(0 <= index && index < n);
		return range_sum(index, index + 1);
	}
};

} // namespace qwertyam

#endif

// ----- LazySegTree [Add & Sum] (end) -----

