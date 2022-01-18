class

# qwertyam::DSU

```cpp
namespace qwertyam {
    class DSU;
}
```

DSU (Disjoint Set Union: 素集合データ構造) が実装されたクラス.

無向グラフに対する以下の操作を高速に行う.

* 辺の追加
* 2つの頂点が連結であるかの判定

グラフの頂点数が N であるとき, それぞれの頂点を, 頂点 0, 頂点 1, ... , 頂点 (N - 1) とする.

各連結成分は代表となる頂点(代表元)を1つ持つ.

## コンストラクタ

```cpp
explicit DSU(const int& N);
```
`N` 頂点 0 辺の無向グラフを生成する.

頂点数を N とすると, 時間計算量は O(N)

## leader

```cpp
int leader(const int& x);
```

頂点 `x` を含む連結成分の代表元を返す.

頂点数を N とすると時間計算量は, ならし O(a(N)) (a(N)はアッカーマン関数 A(N, N)の逆関数)

## merge

```cpp
bool merge(int x, int y);
```

頂点 `x` が含まれる連結成分と, 頂点 `y` が含まれる連結成分をマージする. ここで, 既に `x` と `y` が連結であれば`false`を返し, そうでなければ, マージした後で `true` を返す.

頂点数を N とすると時間計算量は, ならし O(a(N))

## same

```cpp
bool same(const int& x, const int& y);
```

頂点 `x` と頂点 `y` が連結であるかどうかを判定する. 

頂点数を N とすると時間計算量は, ならし O(a(N))

## is_leader

```cpp
bool is_leader(const int& x) const;
```

頂点 `x` が属する連結成分の代表元が `x` であるかを判定する.

時間計算量は O(1)

## set_count

```cpp
int set_count() const;
```

連結成分の個数を返す.

時間計算量は O(1)

## size

```cpp
int size(const int& x);
```

頂点 `x` が属する連結成分について, その連結成分に含まれる頂点の個数を返す.

頂点数を N とすると時間計算量は, ならし O(a(N))

## 例
```cpp

#include "DSU.hpp"
#include <iostream>

int main() {
	int N = 5;
	qwertyam::DSU dsu(N);
	dsu.merge(0, 2);
	dsu.merge(1, 3);
	dsu.merge(2, 3);

	std::cout << dsu.set_count() << std::endl;
	// 2
	std::cout << dsu.size(0) << std::endl;
	// 4
	std::cout << (dsu.is_leader(4) ? "true" : "false") << std::endl;
	// true
	std::cout << (dsu.same(0, 1) ? "true" : "false") << std::endl;
	// true
	return 0;
}

```
