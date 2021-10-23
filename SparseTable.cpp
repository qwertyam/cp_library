template <typename T, T (*OP) (T, T)>
struct SparseTable {
	private: 
		int sz;
		int log_sz;
		std::vector<std::vector<T>> table;
		std::vector<int> log_table;

	public:
		SparseTable(std::vector<T>& v) {
			sz = (int) v.size();
			log_sz = 0;
			while ((1 << (log_sz + 1)) <= sz) {
				log_sz++;
			}
			table = std::vector<std::vector<T>> (log_sz + 1, std::vector<T> (sz, 0));
			for (int i = 0; i < sz; i++) {
				table[0][i] = v[i];
			}
			for (int i = 1; i <= log_sz; i++) {
				int len = (1 << i);
				for (int j = 0; j + len <= sz; j++) {
					table[i][j] = OP(table[i - 1][j], table[i - 1][j + len / 2]);
				}
			}
			log_table = std::vector<int> (sz + 1, -1);
			for (int i = 1; i <= sz; i++) {
				log_table[i] = log_table[i / 2] + 1; 
			}
		}

		T range_calc(int l, int r) {
			assert(0 <= l && l <= r && r < sz);
			int log_len = log_table[r - l + 1];
			int len = (1 << log_len);
			return OP(table[log_len][l], table[log_len][r - len + 1]);
		}
}; // SparseTable

