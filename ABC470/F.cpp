#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i,l,r) for(ll i=(l);i<(r);++i)
#define all(x) (x).begin(),(x).end()

using ll=long long;
using pl=pair<ll,ll>;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using vvvl=vector<vector<vector<ll>>>;
using vvvvl=vector<vector<vector<vector<ll>>>>;
#include<regex>

using mint=modint998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num,edgecnt;
    cin>>num>>edgecnt;

    string text;
    cin>>text;
    dsu graph(num);
    rep(i,0,edgecnt){
        int fpos,spos;
        cin>>fpos>>spos;
        fpos--;
        spos--;
        graph.merge(fpos,spos);
    }
    vector<mint>fact(num+1,1);
    rep(i,1,num+1){
        fact[i]=fact[i-1]*i;
    }
    vector<vector<int>> glist=graph.groups();
    mint ans=1;
    bool chofuku=false;
    for(vector<int> group:glist){
        vector<int> charcnt(26,0);
        for(int pos:group){
            int charnum=text[pos]-'a';
            charcnt[charnum]++;
        }
        mint gways=fact[group.size()];
        rep(charnum,0,26){
            gways/=fact[charcnt[charnum]];
            if(charcnt[charnum]>=2){
                chofuku=true;
            }
        }
        ans*=gways;
    }
    if(!chofuku){
        ans/=2;
    }

    cout<<ans.val()<<'\n';
}