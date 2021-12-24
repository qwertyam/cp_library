
// "range add query" and "range minimum query"

struct LazySegmentTree {
/*
private:
int N, sz, log;
std::vector<int> val, lazy;
void push(int k);
void update(int k); 

public:
explicit LazySegmentTree(const std::vector<int>& v);
void range_add(int l, int r, int x);
int range_min(int l, int r);
*/

private:
	int N, sz, log;

	std::vector<int> val, lazy;

	void push(int k) {
		assert(0 <= k && k < 2 * N);
		val[k] += lazy[k];
		if (k < N) {
			lazy[2 * k] += lazy[k];
			lazy[2 * k + 1] += lazy[k];
		}
		lazy[k] = 0;
	}

	void update(int k) {
		assert(0 <= k && k < N);
		push(2 * k);
		push(2 * k + 1);
		val[k] = std::min(val[2 * k], val[2 * k + 1]);
	}

public:
	explicit LazySegmentTree(const std::vector<int>& v) {
		sz = (int) v.size();
		N = 1;
		log = 0;
		while (N < sz) {
			N *= 2;
			log++;
		}
		val = std::vector<int> (2 * N, 1e9);
		lazy = std::vector<int> (2 * N, 0);
		for (int i = 0; i < sz; i++) {
			val[N + i] = v[i];
		}
		for (int i = N - 1; i >= 0; i--) {
			update(i);
		}
	}

	void range_add(int l, int r, int x) {
		assert(0 <= l && l <= r && r < sz);
		l += N;
		r += N;
		for (int i = log; i > 0; i--) {
			if (((l >> i) << i) != l) {
				push(l >> i);
			}
			if ((((r + 1) >> i) << i) != r + 1) {
				push(r >> i);
			}
		}
		int l2 = l;
		int r2 = r;
		while (l <= r) {
			if (l % 2 == 0) {
				l /= 2;
			}
			else {
				lazy[l] += x;
				l = l / 2 + 1;
			}
			if (r % 2 == 0) {
				lazy[r] += x;
				r = r / 2 - 1;
			}
			else {
				r /= 2;
			}
		}
		l = l2;
		r = r2;
		for (int i = 1; i <= log; i++) {
			if (((l >> i) << i) != l) {
				update(l >> i);
			}
			if ((((r + 1) >> i) << i) != r + 1) {
				update(r >> i);
			}
		}
	}

	int range_min(int l, int r) {
		assert(0 <= l && l <= r && r < sz);
		l += N;
		r += N;
		for (int i = log; i > 0; i--) {
			if (((l >> i) << i) != l) {
				push(l >> i);
			}
			if ((((r + 1) >> i ) << i) != r + 1) {
				push(r >> i);
			}
		}
		int l_res = 1e8;
		int r_res = 1e8;
		while (l <= r) {
			if (l % 2 == 0) {
				l /= 2;
			}
			else {
				push(l);
				l_res = std::min(l_res, val[l]);
				l = l / 2 + 1;
			}
			if (r % 2 == 0) {
				push(r);
				r_res = std::min(val[r], r_res);
				r = r / 2 - 1;
			}
			else {
				r /= 2;
			}
		}
		return std::min(l_res, r_res);
	}
}; // LazySegmentTree


