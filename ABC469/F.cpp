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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin>>num;

    vector<int>alist(num);

    int maxnum=0;
    //alistの最大値を見る
    for(int i=0;i<num;i++){
        cin>>alist[i];
        maxnum=max(maxnum,alist[i]);
    }
    //最大値までのvalueposをまず作る,valuepos[i]はiという値が何番目の入力化を保存
    vector<int>valuepos(maxnum+1,-1);
    for(int i=0;i<num;i++){
        valuepos[alist[i]]=i;
    }
    //num個の頂点を持つgraphを作成(それぞれの頂点がどの連結部分に属するか管理する)
    dsu graph(num);
    //重みの合計
    ll ans=0;
    //最大値から順にみていき公約数を調べる
    for(int divisor=maxnum;divisor>=1;divisor--){
        //alistに存在しない前提で今のdivisorのposを-1とする
        int basepos=-1;
        //今見ている値の倍数の位置を見る(alistに存在するならvaluepos!=-1)
        for(int multiple=divisor;multiple<=maxnum;multiple+=divisor){
            int nowpos=valuepos[multiple];
            //nowpos==-1ならその値はalistにないので次の値へ
            if(nowpos==-1){
                continue;
            }
            //nowpos!=-1(divisorを約数に持つ値multipleが存在する)でありながらbasepose==-1(まだ見つかってなかった)ならbaseposを移動
            if(basepos==-1){
                basepos=nowpos;
                continue;
            }
            //graphのbaseposとnowposが未連結なら重みdivisorの偏として採用する
            if(!graph.same(basepos,nowpos)){
                graph.merge(basepos,nowpos);
                ans+=divisor;
            }
        }
    }

    cout<<ans<<'\n';
}
