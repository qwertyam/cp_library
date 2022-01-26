class

# qwertyam::SegTree

```cpp
namespace qwertyam {
    template <typename T>
    class SegTree;
}
```

セグメント木が実装されたクラス.

## コンストラクタ

```cpp
SegTree (const std::vector<T> &vec, T (*op) (T a, T b), const T& e);
```

`op` は `vec` に対して行う演算である. 例えば, 区間最大値を計算するセグメント木では, `std::max`である.

`e` は, 演算 `op` における単位元である. 例えば, 区間最大値を計算するセグメント木では, `vec` のどの要素よりも小さな値である.

時間計算量は, `vec` の要素数を N として, O(N log N).

## add

```cpp
void add(int index, const T& x);
```

配列の `index` 番目の要素に `x` を加える. 

配列の要素数を N として, 時間計算量は O(log N).

## update

```cpp
void update(int index, const T& x);
```

配列の `index` 番目の要素を `x` にする. 

配列の要素数を N として, 時間計算量は O(log N).

## range_calc

```cpp
T range_calc(int left, int right) const;
```

区間 [`left`, `right` - 1] に対するクエリを処理する. クエリの内容は, コンストラクタの `op` で指定したものである.

配列の要素数を N として, 時間計算量は O(log N).

## get

```cpp
T get(const int& index) const
```

配列の `index` 番目の要素を得る.

時間計算量は O(1)

## 例

```cpp

#include "SegTree.hpp"
#include <iostream>
#include <algorithm>

int op(int a, int b) {
	return std::max(a, b);
}
int e = -100;

int main() {
	std::vector<int> vec = {1, 2, 5, 3,  9};
	qwertyam::SegTree<int> seg(vec, op, e);
	std::cout << seg.range_calc(1, 4) << std::endl;
	// 5
	seg.add(2, 4);
	std::cout << seg.range_calc(1, 4) << std::endl;
	// 9
	seg.update(4, 11);
	std::cout << seg.range_calc(0, 5) << "\n";
	// 11
	return 0;
}

```
