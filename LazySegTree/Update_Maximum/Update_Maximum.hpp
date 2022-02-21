
// ----- LazySegTree [Update & Maximum] (begin) -----

#ifndef QWERTYAM_LAZYSEGTREE_UPDATE_MAXIMUM_HPP
#define QWERTYAM_LAZYSEGTREE_UPDATE_MAXIMUM_HPP

#include <cassert>
#include <vector>
#include <algorithm>
#include <limits>

namespace qwertyam {

template <typename T>
class LazySegTree_Update_Maximum {
private:
	// length of input array
	int n;

	// power of 2 which is equal or more than n
	int n2;

	// log n2
	int log;

	std::vector<T> val, lazy;

	// If lazy_empty[i] is true, lazy[i] is not a propagation value (i.e. empty).
	std::vector<bool> lazy_empty;

	// propagate lazy[k]
	void push(const int& k) {
		assert(0 <= k && k < 2 * this->n2);
		if (this->lazy_empty[k]) return;

		this->val[k] = this->lazy[k];
		if (k < this->n2) {
			this->lazy[2 * k] = this->lazy[k];
			this->lazy[2 * k + 1] = this->lazy[k];
			this->lazy_empty[2 * k] = false;
			this->lazy_empty[2 * k + 1] = false;
		}
		this->lazy[k] = 0;
		this->lazy_empty[k] = true;
	}

	// update val[k]
	void update(const int& k) {
		assert(0 <= k && k < n2);
		this->push(2 * k);
		this->push(2 * k + 1);
		this->val[k] = std::max(this->val[2 * k], this->val[2 * k + 1]);
	}

public:
	explicit LazySegTree_Update_Maximum(const std::vector<T>& vec) {
		this->n = vec.size();
		this->n2 = 1;
		this->log = 0;
		while (this->n2 < this->n) {
			this->n2 *= 2;
			this->log++;
		}
		this->val = std::vector<T> (2 * this->n2, 0);
		this->lazy = std::vector<T> (2 * this->n2, 0);
		this->lazy_empty = std::vector<bool> (2 * this->n2, true);
		for (int i = 0; i < this->n; i++) this->val[this->n2 + i] = vec[i];
		for (int i = n2 - 1; i > 0; i--) this->update(i);
	}

	// update range [left, right - 1] with x
	void range_update(int left, int right, T x) {
		assert(0 <= left && left < right && right <= this->n);
		left += this->n2;
		right += this->n2;
		for (int i = this->log; i > 0; i--) {
			if (left >> i << i != left) this->push(left >> i);
			if (right >> i << i != right) this->push(right >> i);
		}
		int left2 = left;
		int right2 = right;
		while (left2 < right2) {
			if (left2 % 2 == 0) left2 /= 2;
			else {
				this->lazy[left2] = x;
				this->lazy_empty[left2] = false;
				left2 = left2 / 2 + 1;
			}
			if (right2 % 2 == 0) right2 /= 2;
			else {
				this->lazy[right2 - 1] = x;
				this->lazy_empty[right2 - 1] = false;
				right2 /= 2;
			}
		}
		for (int i = 1; i <= this->log; i++) {
			if (((left >> i) << i) != left) this->update(left >> i);
			if (((right >> i) << i) != right) this->update(right >> i);
		}
	}

	T range_max(int left, int right) {
		assert(0 <= left && left < right && right <= this->n);
		left += this->n2;
		right += this->n2;
		for (int i = this->log; i > 0; i--) {
			if (left >> i << i != left) this->push(left >> i);
			if (right >> i << i != right) this->push(right >> i);
		}
		T l_res = std::numeric_limits<T>::min();
		T r_res = std::numeric_limits<T>::min();
		while (left < right) {
			if (left % 2 == 0) left /= 2;
			else {
				this->push(left);
				l_res = std::max(l_res, this->val[left]);
				left = left / 2 + 1;
			}
			if (right % 2 == 0) right /= 2; 
			else {
				this->push(right - 1);
				r_res = std::max(this->val[right - 1], r_res);
				right /= 2;
			}
		}
		return std::max(l_res, r_res);
	}

	T get(const int& index) {
		assert(0 <= index && index < this->n);
		return this->range_max(index, index + 1);
	}
};

} // namespace qwertyam

#endif

// ----- LazySegTree [Add & Minimum] (end) -----


