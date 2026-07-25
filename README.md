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
(追記:26/07/25)AtCoderライブラリにタイをウするようにテンプレを変更．また，なんか上位勢が使っていたのでfor文とvector全要素選択のdefineも追加．QiitaによるとAtCoderの素数は大抵998244353らしいのでそれも追加
```C++
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using pl = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vvvl = vector<vector<vector<ll>>>;
using vvvvl = vector<vector<vector<vector<ll>>>>;
#include <regex>
using mint=modint998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    cin >> a;
    cout << a*2 << '\n';
}
```
##　それぞれの略記などの使い方
``` rep(i,l,r)```の場合
```C++
for (long long i=l,i<r;i++){
    何らかの処理
}
==
rep(i,l,r){
    何らかの処理
}
```
``` all(x)```の場合
```C++
vector<int> v={3,1,4,1,5};

//従来のvの昇順ソート
sort(v.begin(),v.end());

//allを使ったvの昇順ソート
sort(all(v));
```
``` mint=modint998244353```の場合
```C++
mint x=998244354;
x==1
//mintで宣言した値は常に%998244353された値となる
```