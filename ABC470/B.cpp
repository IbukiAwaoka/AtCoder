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

    int num;
    cin >> num;
    vl Col(num);
    rep(i,0,num){
        cin>>Col[i];
    }
    vl countC(num+1,0);
    rep(i,0,num){
        countC[Col[i]]++;
    }
    auto maxval=max_element(all(countC));
    cout<< num-*maxval <<'\n';

}