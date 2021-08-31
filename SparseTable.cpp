template<typename T>
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
        while((1 << (log_sz + 1)) <= sz) {
            log_sz++;
        }
        table = std::vector<std::vector<T>> (log_sz + 1, std::vector<T> (sz, 0));
        for(int i = 0; i < sz; i++) {
            table[0][i] = v[i];
        }
        for(int i = 1; i <= log_sz; i++) {
            int len = (1 << i);
            for(int j = 0; j + len <= sz; j++) {
                table[i][j] = std::max(table[i - 1][j], table[i - 1][j + len / 2]);
            }
        }
        log_table = std::vector<int> (sz + 1, -1);
        for(int i = 1; i <= sz; i++) {
            log_table[i] = log_table[i / 2] + 1; 
        }
    }

    T query(int l, int r) {
        int log_len = log_table[r - l + 1];
        int len = (1 << log_len);
        return std::max(table[log_len][l], table[log_len][r - len + 1]);
    }
};

