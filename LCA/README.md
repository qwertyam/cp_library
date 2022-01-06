class

# qwertyam::LCA

```cpp
namespace qwertyam {
    class LCA;
}
```
根付き木上の2点のLCA (Lowest Common Ancestor : 最近共通祖先)を求める.

根付き木の頂点数が N であるとき, N 個の頂点をそれぞれ頂点0, 頂点1, 頂点2, ... , 頂点(N - 1) とする.

ダブリングを用いて実装されており, オブジェクトの構築を O (N log N), LCAを求めるクエリの処理を O (log N) の時間計算量で行う.

## コンストラクタ

```cpp
LCA(const std::vector<std::vector<int>>& adjacency_list, const int root_vertex);
```

木の隣接リスト `adjacency_list` と, 根となる頂点 `root_vertex` を引数にとる. ここで木の頂点数を N とすると, `root_vertex` は 0 以上 N 未満の整数出なくてはならない.

頂点数が N のとき, 時間計算量は O (N log N)

## query

```cpp
int query(int v1, int v2);
```

`v1` と `v2` の LCA を求める.

頂点数が N のとき, 時間計算量は O (log N)