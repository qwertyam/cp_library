struct SCC {
	private:
		int N;
		std::vector<int> V; 
		std::vector<bool> used;
		std::vector<std::vector<int>> Graph;
		std::vector<std::vector<int>> rev_Graph;
		std::vector<std::vector<int>> SCC_vec;

		void dfs_1(int now_v) {
			used[now_v] = true;
			for (int next_v : Graph[now_v]) {
				if (used[next_v] == false) {
					dfs_1(next_v);
				}
			}
			V.push_back(now_v);
		}

		void dfs_2(int now_v, std::vector<int>& vec) {
			vec.push_back(now_v);
			used[now_v] = true;
			for (int next_v : rev_Graph[now_v]) {
				if (used[next_v] == false) {
					dfs_2(next_v, vec);
				}
			}
		}

	public:
		SCC (std::vector<std::vector<int>>& G) {
			N = int(G.size());
			used = std::vector<bool> (N, false);
			Graph = G;
			rev_Graph = std::vector<std::vector<int>> (N);
			for (int i = 0; i < N; i++) {
				for (int j : Graph[i]) {
					rev_Graph[j].push_back(i);
				}
			}
			for (int i = 0; i < N; i++) {
				if (used[i] == false) {
					dfs_1(i);
				}
			}
			std::reverse(V.begin(), V.end());
			for (int i = 0; i < N; i++) {
				used[i] = false;
			}
			for (int i : V) {
				if (used[i] == true) {
					continue;
				}
				std::vector<int> vec;
				dfs_2(i, vec);
				SCC_vec.push_back(vec);
			}
		}

		std::vector<std::vector<int>> get_SCC_vec() {
			return SCC_vec; 
		}
};

