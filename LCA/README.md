class

# qwertyam::LCA

```cpp
namespace qwertyam {
    class LCA;
}
```
根付き木上の2点のLCA (Lowest Common Ancestor : 最近共通祖先)を求める.

根付き木の頂点数が N であるとき, N 個の頂点をそれぞれ頂点0, 頂点1, 頂点2, ... , 頂点(N - 1) とする.

ダブリングを用いて実装されており, オブジェクトの構築を O (N log N), LCAを求めるクエリの処理を O (log N) の時間計算量で行う.

## コンストラクタ

```cpp
LCA(const std::vector<std::vector<int>>& adjacency_list, const int& root_vertex);
```

木の隣接リスト `adjacency_list` と, 根となる頂点 `root_vertex` を引数にとる. ここで木の頂点数を N とすると, `root_vertex` は 0 以上 N 未満の整数でなくてはならない.

頂点数が N のとき, 時間計算量は O (N log N)

## query

```cpp
int query(int v1, int v2);
```

`v1` と `v2` の LCA を求める.
ここで木の頂点数を N とすると, `v1`, `v2` は 0 以上 N 未満の整数でなくてはならない.

頂点数が N のとき, 時間計算量は O (log N)

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
	std::cout << lca.query(0, 4) << std::endl;
	std::cout << lca.query(2, 4) << std::endl;
	std::cout << lca.query(1, 3) << std::endl;
	return 0;
}
```