# AtCoder
A record of my AtCoder history

# 主な使用言語について
```C++,Python```

これまで，CとC＋＋の混合としてCppを使っていたが，これからはアルゴリズム用にCppの書き方をメインとする．
Cは書けるがCppは怪しい部分があるので勉強をしていく
Pythonは基本的にPyPy3を使っていく．Numbaを活用したPython3とちがって使用メモリ量は多くなるがその分メモリ制限を気にするためアルゴリズムをメインに書くことになる．
Cppの書き方がわからなくなった時にPyPy3を使ってごまかすのが主な使い方となる．

# C++で使いまわすテンプレート
毎回書くことはほぼ同じ部分があるので使いまわしする．
```C++
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    cin >> a;
    cout << a*2 << '\n';
}
```