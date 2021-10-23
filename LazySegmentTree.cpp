// type = long long
// update = range add query
// range_calc = range max query
struct LazySegmentTree {
	private:
		int N;
		int sz;
		int log;
		std::vector<long long> tree;
		std::vector<long long> lazy;

		void push(int k) {
			assert(0 <= k && k < 2 * N);
			tree[k] += lazy[k];
			if (k < N) {
				lazy[2 * k] += lazy[k];
				lazy[2 * k + 1] += lazy[k];
			}
			lazy[k] = 0;
		}

		void update(int k) {
			assert(0 <= k && k < 2 * N);
			tree[k] = std::max(tree[2 * k], tree[2 * k + 1]);
		}

	public:
		LazySegmentTree (const std::vector<long long>& v) {
			N = 1;
			sz = (int) v.size();
			log = 0;
			while (N < sz) {
				N *= 2;
				log++;
			}
			tree = std::vector<long long> (2 * N, -1e18);
			lazy = std::vector<long long> (2 * N, 0); 
			for (int i = 0; i < sz; i++) {
				tree[N + i] = v[i];
			}
			for (int i = N - 1; i >= 1; i--) {
				tree[i] = std::max(tree[2 * i], tree[2 * i + 1]);
			}
		}

		long long get(int ind) {
			return tree[ind + N];
		}

		void update(int l, int r, int x) {
			assert(0 <= l && l <= r && r < sz);
			l += N;
			r += N;
			for (int i = log; i >= 1; i--) {
				if (((l >> i) << i) != l) {
					push(l >> i);
				}
				if ((((r + 1) >> i) << i) != (r + 1)) {
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
					push(l);
					l = l / 2 + 1;
				}
				if (r % 2 == 0) {
					lazy[r] += x;
					push(r);
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
				if ((((r + 1) >> i) << i) != (r + 1)) {
					update(r >> i);
				} 
			}
		}

		long long range_calc(int l, int r) {
			assert(0 <= l && l <= r && r < sz);
			l += N;
			r += N;
			for (int i = log; i >= 1; i--) {
				if (((l >> i) << i) != l) {
					push(l >> i);
				}
				if ((((r + 1) >> i) << i) != (r + 1)) {
					push(r >> i);
				}
			}   
			long long l_res = -1e18;
			long long r_res = -1e18;
			while (l <= r) {
				if (l % 2 == 0) {
					l /= 2;
				}
				else {
					push(l);
					l_res = std::max(l_res, tree[l]);
					l = l / 2 + 1;
				}
				if (r % 2 == 0) {
					push(r);
					r_res = std::max(tree[r], r_res);
					r = r / 2 - 1;
				}
				else {
					r /= 2;
				}
			}
			return std::max(l_res, r_res);
		}
}; // LazySegmentTree

