class

# qwertyam::SCC


```cpp
namespace qwertyam {
    class SCC;
}
```

有向グラフに対して強連結成分分解を行うクラス.

## コンストラクタ

```cpp
explicit SCC (const std::vector<std::vector<int>>& AdjacencyList);
```

有向グラフの隣接リスト `AdjacencyList` を引数にとる. 

頂点数を N, 辺数を M とすると, 時間計算量は O (N + M).

## get_scc

```cpp
std::vector<std::vector<int>> get_scc() const;
```

強連結成分分解した結果を返す. 結果は `std::vector` による2次元配列として表現されており, 各1次元配列は強連結成分である.

2次元の `std::vector` をコピーして返すため, 辺数を M とすると, 時間計算量は O (M).

## scc_count

```cpp
int scc_count() const;
```

強連結成分の個数を返す. 時間計算量は O (1).

## 例

```cpp
#include "SCC.hpp"
#include <iostream>
#include <vector>

int main() {
	int N = 4;
	std::vector<std::vector<int>> AdjacencyList(N);
	AdjacencyList[0] = {1, 2, 3};
	AdjacencyList[1] = {2};
	AdjacencyList[2] = {0};
	AdjacencyList[3] = {};
	qwertyam::SCC scc(AdjacencyList);
	std::vector<std::vector<int>> scc_result = scc.get_scc();
	for (std::vector<int> vec : scc_result) {
		for (int v : vec) std::cout << v << " ";
		std::cout << std::endl;
	}
	// 0 2 1
	// 3
	std::cout << scc.scc_count() << std::endl;
	// 2
	return 0;
}
```
