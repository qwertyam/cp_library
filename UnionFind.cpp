struct UnionFind {
private:
    int N;
    int tree_cnt_data;
    std::vector<int> val;

    int root(int x) {
        if (val[x] < 0) {
            return x;
        }
        else {
            return val[x] = root(val[x]);
        }
    }

public:
    UnionFind(int n) {
        N = n;
        tree_cnt_data = n;
        val = std::vector<int> (n, -1);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) {
            return;
        }
        if (val[x] > val[y]) {
            std::swap(x, y);
        }
        val[x] += val[y];
        val[y] = x;
        tree_cnt_data--;
        return;
    }

    bool same(int x, int y) {
        if (root(x) == root(y)) {
            return true;
        }
        else {
            return false;
        }
    }

    int tree_cnt() {
        return tree_cnt_data;
    }

    int tree_size(int x) {
        return -val[root(x)];
    }

    bool is_root(int x) {
        return (val[x] < 0 ? true : false);
    }
}; // UnionFind

