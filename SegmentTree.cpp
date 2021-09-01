template<typename T, T (*OP) (T, T), T (*E) ()>
struct SegmentTree {
private:
    int N;
    int sz;
    std::vector<T> tree;

public:
    SegmentTree(const std::vector<T>& v) {
        N = 1;
        sz = (int) v.size();
        while (N < sz) {
            N *= 2; 
        }
        tree = std::vector<T> (2 * N, E());
        for (int i = 0; i < sz; i++) {
            tree[N + i] = v[i];
        }
        for(int i = N - 1; i >= 1; i--) {
            tree[i] = OP(tree[2 * i], tree[2 * i + 1]);
        }
    }

    T get(int ind) const {
        assert(0 <= ind && ind < sz);
        return tree[N + ind];
    }

    void update(int ind, T x) {
        assert(0 <= ind && ind < sz);
        ind += N;
        tree[ind] = x;
        while (ind > 0) {
            ind /= 2;
            tree[ind] = OP(tree[2 * ind], tree[2 * ind + 1]);
        }
    }

    T range_calc(int l, int r) {
        assert(0 <= l && l <= r && r < sz);
        l += N;
        r += N;
        T l_res = E();
        T r_res = E();
        while (l <= r) {
            if (l % 2 == 0) {
                l /= 2; 
            }
            else {
                l_res = OP(l_res, tree[l]); 
                l = l / 2 + 1;
            }
            if (r % 2 == 0) {
                r_res = OP(tree[r], r_res);
                r = r / 2 - 1;
            }
            else {
                r /= 2;
            }
        }
        return OP(l_res, r_res);
    }
};

