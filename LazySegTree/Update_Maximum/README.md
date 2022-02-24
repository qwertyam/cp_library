class

# qwertyam::LazySegTree_Update_Maximum

```cpp
namespace qwertyam {
    template <typename T>
    class LazySegTree_Update_Maximum;
}
```

以下の2つのクエリを処理する遅延セグメント木が実装されたクラス.

* 区間更新クエリ
* 区間最大値クエリ

## コンストラクタ

```cpp
explicit LazySegTree_Update_Maximum(const std::vector<T>& vec);
```

`vec` の要素数を N として, 時間計算量は O(N log N).

## range_update

```cpp
void range_update(int left, int right, T x);
```

区間加算クエリを処理する. 区間 [`left`, `right` - 1] の値を `x` に更新する.

配列の要素数を N として, 時間計算量は O(log N).

## range_max

```cpp
T range_max(int left, int right);
```

区間最大値クエリを処理する. 区間 [`left`, `right` - 1] の最大値を返す.

配列の要素数を N として, 時間計算量は O(log N).

# get

```cpp
T get(const int& index);
```

配列の `index` 番目の要素を取得する.

配列の要素数を N として, 時間計算量は O(log N).

## 例

```cpp
#include "Update_Maximum.hpp"
#include <iostream>
#include <vector>
int main() {
	std::vector<int> vec = {3, 1, 4, 1, 5};
	qwertyam::LazySegTree_Update_Maximum<int> lseg(vec);
	std::cout << lseg.range_max(0, 5) << std::endl; // 5
	lseg.range_update(0, 3, 10);
	std::cout << lseg.range_max(2, 5) << std::endl; // 10
	std::cout << lseg.get(1) << std::endl; // 10
	return 0;
}
```
