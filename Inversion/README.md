function

# qwertyam::Inversion

```cpp
namespace qwertyam {
    template <typename T>
    long long Inversion(const std::vector<T>& vec);
}
```

数列 `vec` の転倒数を `long long` 型で返す関数.

`vec` の各要素は非負の整数でなくてはならない.

また, `vec` の最大の要素を M とすると, 内部で O (M) のサイズの配列を作るため, `vec` の各要素は最大でも, 10^6 程度でなくてはならない.