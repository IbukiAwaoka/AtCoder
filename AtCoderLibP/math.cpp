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

    int casenum;
    cin >> casenum;
    int num,yuka,fis,sec;
    rep(i,0,casenum){
        cin>>num>>yuka>>fis>>sec;
        cout<<floor_sum(num,yuka,fis,sec)<<'\n';
    }
}