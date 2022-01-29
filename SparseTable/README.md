class

# qwertyam::SparseTable

```cpp
namespace qwertyam {
    template <typename T>
    class SparseTable;
}
```

スパーステーブルが実装されたクラス.

1次元配列に対して, 冪等性を満たす演算の区間クエリを O (1) で行う.

## コンストラクタ

```cpp
SparseTable(const std::vector<T>& vec, T (*_op) (T a, T b));
```

`op` は, 配列に対する演算を定義する.

配列の要素数を N とすると, 時間計算量は O (N log N).

## range_calc

```cpp
T range_calc(const int& left, const int& right) const;
```

区間 [`left`, `right` - 1] に対するクエリを処理する.

時間計算量は O (1).

## 例
```cpp
#include "SparseTable.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int op(int a, int b) {
	return std::max(a, b);
}

int main() {
	std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2};
	qwertyam::SparseTable<int> spt(vec, op);
	std::cout << spt.range_calc(0, 7) << std::endl;
	// 9
	return 0;
}
```