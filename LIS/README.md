class

# qwertyam::LIS

```cpp
namespace qwertyam {
    template <typename T>
    class LIS;
}
```

数列の LIS (Longest Increasing Subsequence : 最長増加部分列) を求める.

## コンストラクタ

```cpp
LIS(const std::vector<T>& vec, const bool& strict = true);
```

`vec` は対象となる数列である. 

`strict` が, `true` のとき狭義単調増加部分列を, `false` のとき広義単調増加部分列を求める.

数列の要素数を N とすると, 時間計算量は O(N log N)

## get_lis
```cpp
std::vector<T> () const;
```

LIS を返す. 

時間計算量は O(1)

## get_len
```cpp
int get_len() const;
```

LIS の長さを返す.

時間計算量は O(1)

## 例
```cpp

#include "LIS.hpp"
#include <vector>
#include <iostream>


int main() {
	std::vector<int> vec = {1, 2, 4, 6, 3, 6};

	qwertyam::LIS<int> lis_1(vec, true);
	auto _lis_1 = lis_1.get_lis();
	std::cout << "Strict LIS: ";
	for (int element : _lis_1) std::cout << element << " ";
	std::cout << std::endl;
	// Strict LIS: 1 2 4 6
	std::cout << "Length: " << lis_1.get_len() << std::endl;
	// Length: 4

	qwertyam::LIS<int> lis_2(vec, false);
	auto _lis_2 = lis_2.get_lis();
	std::cout << "Not Strict LIS: ";
	for (int element : _lis_2) std::cout << element << " ";
	std::cout << std::endl;
	// Not Strict LIS: 1 2 4 6 6
	std::cout << "Length: " << lis_2.get_len() << std::endl;
	// Length: 5

	return 0;
}

```
