[TOC]

# purpose

メモ用として、今まで、自分が実装してきたアルゴリズムをまとめている。



# math 



|              | 概要                                                         | 計算量 | 実行例 |
| ------------ | ------------------------------------------------------------ | ------ | ------ |
| mod_pow      | 繰り返し２乗法を用いて、指数計算を高速で行い、それを指定した値で割った余りを返す。 | TBC    | TBC    |
| pow          | 繰り返し２乗法を用いて、指数計算を高速で行い、その結果を返す。 | TBC    | TBC    |
| Eratosthenes | ２以上の自然数N以下の素数を列挙するアルゴリズム              | TBC    |        |
|              |                                                              |        |        |
|              |                                                              |        |        |



# Graph theory

設計思想：edgeクラスとgraphクラスはすべてで共通のものを使用して、それ以外の関数はアルゴリズムごとに細部が異なるため、個々に実装している。



実装アルゴリズム集

| アルゴリズム名                      | 概要                                                         |                    | 実行例                                                       |
| ----------------------------------- | ------------------------------------------------------------ | ------------------ | ------------------------------------------------------------ |
| Dykstra                             | 与えられた無向グラフのある一つのノードからその他のすべてのノードへの最短距離を求めるアルゴリズム。 | O((N+M)logN)       | 典型:013                                                     |
| bipartite_maching                   | 二部グラフが与えられたときに、capacityを超えない範囲でマッチング数が最大となる組み合わせを見つけるアルゴリズム。 | TBC                |                                                              |
| maximum_flow                        | 与えられたグラフに対して、始点となるノードから終点となるノードに至るまで、エッジのキャパシティを超えない範囲で最大の流量となるようなフローを求めるアルゴリズム | TBC                |                                                              |
| minimize_cost                       | 与えられたグラフに対して、始点となるノードから終点となるノードに至るまで、キャパを超えない範囲でエッジに付与されたコストを最小化するようなフローを求めるアルゴリズム | TBC                |                                                              |
| color_assign                        | 与えられたグラフのノードをN色で塗り分けるようアルゴリズム。BFSを用いて実装されている。げんざい、２色のみに対応 | TBC                |                                                              |
| *Strongly Connected Component (SCC) | 与えられた有効グラフを復数の強連結成分に分解する。           |                    | [典型21](https://atcoder.jp/contests/typical90/tasks/typical90_u) |
| Prim                                | 与えられた無向グラフの最小全域木を求める手法<br>はじめにランダムにノードを１点選び、その後、選択済のノードから未選択のノードへのエッジの中で、コストが最小のものを選択し続ける手法 | O(\|E\|log \|V\|)  | [Aizu_GRL_2_A](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja) |
| Kruskal                             | 与えられた無向グラフの最小全域木を求める手法<br/>残っている辺の中からコストが最小の辺 e を取り出す。現在構成中の T に e を加えても閉路ができないなら T に加える。（[引用](https://algo-logic.info/kruskal-mst/)） | log(\|E\|log\|V\|) | [Aizu_GRL_2_A](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja) |
| warshall-floyd                      | 与えられた有効グラフのすべてのノードからその他のすべてのノードへの最短距離を求めるアルゴリズム。 | O ($n^{3}$)        |                                                              |

# tree.hpp



アルゴリズム集

| アルゴリズム名             | 概要                                                         | 実行例                                                       |
| -------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Union_Find                 | 木構造を用いてグループ分けを高速に処理するアルゴリズム<br />はじめは、各メンバーをすべて異なるグループに属すると考え、その後同じグループに属するメンバーを統合していく。その性質上、一度グループに属するとみなされた場合、抜け出すことはできない。 | TBC                                                          |
| Segment Tree（範囲最大化） | 完全二部木を用いて、指定した範囲内で最大（最小）となる値を算出するアルゴリズム。<br>通常、配列の各要素の値を上書きをするときは、葉のノードからルートに至るまで更新していくため、範囲内の復数の要素を更新するときは時間がかかるが、キャッシュを活用して、ルートノードから下に向けて更新作業をすることで時間を短縮する。([実装参考例](https://github.com/E869120/kyopro_educational_90/blob/main/sol/029-03.cpp)） | [典/型029](https://atcoder.jp/contests/typical90/tasks/typical90_ac) |
| Tree                       | Graph.hppで実装しているgraphクラスだと、木構造の処理が複雑になるため、木構造用に作成。下記特徴<br>N: ノード数, E: エッジ数<br>  - 木構造作成 O(E)<br>  - 各要素のアクセス O(1)<br>  - 各ノードの親ノード子ノードへのアクセス O(1)<br>  - 全葉ノードの取得 O(N)<br>  -  指定したノードの全子孫ノード数 O(E)   //キャッシュ機能あり |                                                              |
|                            |                                                              |                                                              |
|                            |                                                              |                                                              |
|                            |                                                              |                                                              |
|                            |                                                              |                                                              |
|                            |                                                              |                                                              |
|                            |                                                              |                                                              |

# bit.hpp

現時点でutility関数のみを実装

| アルゴリズム名 | 概要                                   | 実行例 |
| -------------- | -------------------------------------- | ------ |
| display        | 整数をビット変換したものを表示させる。 |        |
|                |                                        |        |
|                |                                        |        |

# pair.hpp

| 関数名       | 概要                                                         | 実行例 |
| ------------ | ------------------------------------------------------------ | ------ |
| pair_greater | vevtor\<pair\>型のソート時の設定を柔軟にするための構造体<br />- pairの第1要素、第2要素のどちらで優先でソートするのか,<br>- 第１要素・第２要素それぞれを降順・昇順のどちらでソートするのか | None   |

# coordinate.hpp

| 関数名   | 概要                                          | 実行例      |
| -------- | --------------------------------------------- | ----------- |
| compress | vector\<int\>などで表現された座標を圧縮させる | O(n long n) |
