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

    //頂点の数とクエリの数を入力
    int num,que;
    cin >> num>>que;
    fenwick_tree<ll> ft(num);
    int ipnum;
    rep(i,0,num){
        cin>>ipnum;
        ft.add(i,ipnum);
    }
    bool type;
    int ui,vi;
    rep(i,0,que){
        cin>>type>>ui>>vi;
        if(!type){
            ft.add(ui,vi);
        }else{
            cout<< ft.sum(ui,vi)<<'\n';
        }
    }
}