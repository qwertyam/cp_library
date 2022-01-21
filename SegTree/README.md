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

## add

```cpp
void add(int index, const T& x);
```
## update

```cpp
void update(int index, const T& x);
```
## range_calc

```cpp
T range_calc(int left, int right) const;
```
## get

```cpp
T get(const int& index) const
```