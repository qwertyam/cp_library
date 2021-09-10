struct LCA {
private:
    int N, log;
    std::vector<int> dist;
    std::vector<std::vector<int>> Graph; 
    std::vector<std::vector<int>> parent;

    void dfs(int v, int p, int d) {
        assert(0 <= v && v < N);
        dist[v] = d;
        parent[0][v] = p;
        for (int nv : Graph[v]) {
            if (nv != p) {
                dfs(nv, v, d + 1);
            }
        }
    }

public:
    LCA (std::vector<std::vector<int>>& G) {
        N = int(G.size());
        log = 1;
        while ((1 << log) < N) {
            log++;
        }
        dist = std::vector<int> (N);
        Graph = G;
        parent = std::vector<std::vector<int>> (log, std::vector<int> (N, -1));
        dfs(0, -1, 0);
        for (int i = 1; i < log; i++) {
            for (int j = 0; j < N; j++) {
                if (parent[i - 1][j] == -1) {
                    parent[i][j] = -1;
                }
                else {
                    parent[i][j] = parent[i - 1][parent[i - 1][j]];
                }
            }
        }
    }

    int query(int u, int v) {
        assert(0 <= u && u < N && 0 <= v && v < N);
        if (dist[u] < dist[v]) {
            std::swap(u, v);
        }
        for (int i = 0; i < log; i++) {
            assert(0 <= u && u < N && 0 <= v && v < N);
            if ((dist[u] - dist[v]) >> i & 1) {
                u = parent[i][u];
            }
        }
        if (u == v) {
            return u;
        }
        for (int i = log - 1; i >= 0; i--) {
            assert(0 <= u && u < N && 0 <= v && v < N);
            if (parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
}; // LCA

