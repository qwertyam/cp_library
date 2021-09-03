struct LIS {
private:
    int sz;
    int N;
    int tmp_length;
    std::vector<int> LIS_vector;
    std::vector<int> tree;
    std::vector<int> order;

    void update(int ind, int x) {
        ind += N;
        tree[ind] = x;
        while (ind >= 1) {
            ind /= 2;
            tree[ind] = std::max(tree[2 * ind], tree[2 * ind + 1]);
        }
    }

    int left_max(int k) {
        int l = N;
        int r = N + k - 1;
        int res = 0;
        while (l <= r) {
            if (l % 2 == 0) {
                l /= 2;
            }
            else {
                res = std::max(res, tree[l]); 
                l = l / 2 + 1;
            }
            if (r % 2 == 0) {
                res = std::max(res, tree[r]);
                r = r / 2 - 1;
            }
            else {
                r /= 2;
            }
        } 
        return res;
    }

public:
    LIS (const std::vector<int>& v) {
        sz = (int) v.size();
        N = 1;
        tmp_length = 0;
        while (N < sz) {
            N *= 2;
        }
        tree = std::vector<int> (2 * N, 0); 
        order = std::vector<int> (sz, 0);
        for (int i = 0; i < sz; i++) {
            assert(0 <= v[i] && v[i] <= 1000000);
            int l_max = left_max(v[i]);
            update(v[i], l_max + 1); 
            order[i] = l_max + 1;
            tmp_length = std::max(tmp_length, l_max + 1);
        }
        int max_val = 1001001001;
        for (int i = sz - 1; i >= 0; i--) {
            if (order[i] == tmp_length && v[i] <= max_val) {
                LIS_vector.push_back(v[i]); 
                tmp_length--;
                max_val = v[i];
            }
        }
        reverse(LIS_vector.begin(), LIS_vector.end());
    }

    std::vector<int> get_LIS() {
        return LIS_vector;
    } 

    int size() {
        return (int) LIS_vector.size();
    }
}; // LIS

