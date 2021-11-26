
/*------ SparseTable (begin) -----*/

template <typename T>
struct SparseTable {
	private:
		std::size_t sz;
		std::size_t log_sz;
		std::vector<std::vector<T>> table;
		std::vector<std::size_t> log_table;

		T op(const T a, const T b) const;

	public:
		SparseTable() {}; 
		explicit SparseTable(const std::vector<T>& v);

		T range_calc(const int left, const int right) const; 
};


template <typename T> 
T SparseTable<T>::op(T a, T b) const {
	// example code
	// return std::min(a, b);
}


template <typename T> 
SparseTable<T>::SparseTable(const std::vector<T> &v) {
	sz = v.size();
	log_sz = 0;
	while ((1 << log_sz) <= sz) log_sz++; 

	table = std::vector<std::vector<T>> (log_sz, std::vector<T> (sz));
	for (int i = 0; i < (int) sz; i++) table[0][i] = v[i];
	for (int i = 1; i < (int) log_sz; i++) {
		std::size_t len = (1 << i);
		for (int j = 0; j + len <= sz; j++) {
			table[i][j] = op(table[i - 1][j], table[i - 1][j + len / 2]);
		}
	}

	log_table = std::vector<std::size_t> (sz + 1);
	log_table[1] = 0;
	for (int i = 2; i <= (int) sz; i++) log_table[i] = log_table[i / 2] + 1; 
}


template <typename T>
T SparseTable<T>::range_calc(const int left, const int right) const {
	assert(0 <= left && left <= right && right < sz);

	std::size_t log_len = log_table[right - left + 1];
	std::size_t len = (1 << log_len);

	assert(0 <= log_len && log_len < log_sz);
	assert(0 <= right - len + 1 && right - len + 1 < sz); 
	return op(table[log_len][left], table[log_len][right - len + 1]);
}

/*------ SparseTable (end) -----*/

