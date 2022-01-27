
class

# qwertyam::LazySegTree_Add_Maximum

```cpp
namespace qwertyam {
    template <typename T>
    class LazySegTree_Add_Maximum;
}
```

以下の2つのクエリを処理する遅延セグメント木が実装されたクラス.

* 区間加算クエリ
* 区間最大値クエリ

## コンストラクタ

```cpp
explicit LazySegTree_Add_Maximum(const std::vector<T>& vec);
```

`vec` の要素数を N として, 時間計算量は O(N log N).

## range_add

```cpp
void range_add(int left, int right, T x);
```

区間加算クエリを処理する. 区間 [`left`, `right` - 1] に対して `x` を加える. `x` を負の数にすることで, 減算も行える.

配列の要素数を N として, 時間計算量は O(log N).

## range_min

```cpp
T range_min(int left, int right);
```

区間最大値クエリを処理する. 区間 [`left`, `right` - 1] の最小値を返す.

配列の要素数を N として, 時間計算量は O(log N).

# get

```cpp
T get(const int& index);
```

配列の `index` 番目の要素を取得する.

配列の要素数を N として, 時間計算量は O(log N).

## 例

```cpp
#include "Add_Maximum.hpp"
#include <iostream>
int main() {
	std::vector<int> vec = {3, 1, 4, 1, 5};
	qwertyam::LazySegTree_Add_Maximum<int> lseg(vec);
	std::cout << lseg.range_max(0, 5) << std::endl;
	// 5 
	lseg.range_add(0, 4, 2);
	std::cout << lseg.range_max(0, 5) << std::endl;
	// 6 
	std::cout << lseg.get(2) << std::endl;
	// 6
	return 0;
}
```
