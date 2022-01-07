class

# qwertyam::LCA

```cpp
namespace qwertyam {
    class LCA;
}
```
根付き木上の2点のLCA (Lowest Common Ancestor : 最近共通祖先)を求める.

根付き木の頂点数が N であるとき, N 個の頂点をそれぞれ頂点0, 頂点1, 頂点2, ... , 頂点(N - 1) とする.

ダブリングを用いて実装されている.

## コンストラクタ

```cpp
LCA(const std::vector<std::vector<int>>& adjacency_list, const int& root_vertex);
```

木の隣接リスト `adjacency_list` と, 根となる頂点 `root_vertex` を引数にとる. ここで木の頂点数を N とすると, `root_vertex` は 0 以上 N 未満の整数でなくてはならない.

頂点数が N のとき, 時間計算量は O (N log N)

## get_lca

```cpp
int get_lca(int v1, int v2) const;
```

2頂点 `v1`, `v2` の LCA を求める.
ここで木の頂点数を N とすると, `v1`, `v2` は 0 以上 N 未満の整数でなくてはならない.

頂点数が N のとき, 時間計算量は O (log N)

## get_root

```cpp
int get_root() const;
```

木の根を返す.

時間計算量は O(1)

## get_dist

```cpp
int get_dist(const int& vertex) const;
```

根から頂点 `vertex` までの距離を返す. ここで木の頂点数が N であるとき, `vertex` は 0 以上 N 未満の整数でなくてはならない.

時間計算量は O(1)

## get_parent

```cpp
int get_parent(const int& vertex) const;
```

頂点 `vertex` の親を返す. ここで頂点数が N であるとき,  `vertex` は 0 以上 N 未満の整数でなくてはならない. なお, 親が存在しない場合 (すなわち `vertex` が根である場合) は `-1` を返す.

時間計算量は O(1)

## 例

```cpp
#include <iostream>
#include <vector>
#include "LCA.hpp"

int main() {
	std::size_t N = 5;
	std::vector<std::vector<int>> adjacency_list(N);
	adjacency_list[0] = {1, 2, 3};
	adjacency_list[1] = {0};
	adjacency_list[2] = {0, 4};
	adjacency_list[3] = {0};
	adjacency_list[4] = {2};

	qwertyam::LCA lca(adjacency_list, 0);

	std::cout << "LCA of 0 and 4 : " << lca.get_lca(0, 4) << std::endl;
	// LCA of 0 and 4 : 0
	std::cout << "LCA of 2 and 4 : " << lca.get_lca(2, 4) << std::endl;
	// LCA of 2 and 4 : 2

	std::cout << "Root : " << lca.get_root() << std::endl;
	// Root : 0

	std::cout << "Distance from root to 0 : " << lca.get_dist(0) << std::endl;
	// Distance from root to 0 : 0
	std::cout << "Distance from root to 2 : " << lca.get_dist(2) << std::endl;
	// Distance from root to 2 : 1
	std::cout << "Distance from root to 4 : " << lca.get_dist(4) << std::endl; 
	// Distance from root to 4 : 2

	std::cout << "Parent of 0 : " << lca.get_parent(0) << std::endl; 
	// Parent of 0 : -1
	std::cout << "Parent of 1 : " << lca.get_parent(1) << std::endl; 
	// Parent of 1 : 0
	std::cout << "Parent of 4 : " << lca.get_parent(4) << std::endl; 
	// Parent of 4 : 2

	return 0;
}
```

## 例題

[AtCoder Beginner Contest 014 D - 閉路](https://atcoder.jp/contests/abc014/tasks/abc014_4)

[実装例](https://atcoder.jp/contests/abc014/submissions/28359501)