class

# qwertyam::ModInv

```cpp
namespace qwertyam {
    class ModInv;
}
```

モジュラ逆数のライブラリ. 

A * X == B (mod M) を満たす最小の非負整数を求める.

## コンストラクタ

```cpp
ModInv(const long long A, long long B, long long M);
```

`A`, `B`, `M` はいずれも正数でなければならない. また, `B` は `M` 未満でなければならない.

## exist

```cpp
bool exist() const;
```

A * X == B (mod M) を満たす X が存在するかを返す.

## X

```cpp
long long X() const;
```

A * X == B (mod M) を満たす最小の非負整数を返す. 解が存在しない場合は `-1` を返す.

## 例

```cpp
#include "ModInv.hpp"
#include <iostream>

int main() {
	qwertyam::ModInv mi(7, 1, 5);
	std::cout << mi.exist() << "\n";
	// 1
	std::cout << mi.X() << "\n";
	// 3
}
```
