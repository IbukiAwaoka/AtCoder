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

    int num,que;
    cin >> num>>que;
    vl Permu(num);
    rep(i,0,num){
        cin>>Permu[i];
    }
    vl tPermu(num);
    rep(i,0,num){
        tPermu[Permu[i]-1]=i+1;
    }
    int ope,posf,poss;
    rep(q,0,que){
        cin>>ope;
        if(ope==1){
            cin>>posf>>poss;
            posf--;
            poss--;
            ll valf=Permu[posf];
            ll vals=Permu[poss];
            swap(Permu[posf],Permu[poss]);
            tPermu[valf-1]=poss+1;
            tPermu[vals-1]=posf+1;
        }else if(ope==2){
            swap(Permu,tPermu);
        }
    }
    rep(i,0,num-1){
        cout<<Permu[i]<<' ';
    }
    cout<<Permu[num-1]<<'\n';
}