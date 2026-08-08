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
    vl ZA(num);
    set<int>active;
    int ope,pos;
    ll xorval=0;
    rep(i,0,que){
        cin>>ope;
        if(ope==1){
            cin>>pos;
            pos--;
            xorval^=ZA[pos];
            ZA[pos]++;
            xorval^=ZA[pos];
            active.insert(pos);
        }else if(ope==2){
            for(auto ite=active.begin();ite!=active.end();){
                int pos=*ite;
                xorval^=ZA[pos];
                ZA[pos]--;
                xorval^=ZA[pos];
                if(ZA[pos]==0){
                    ite=active.erase(ite);
                }else{
                    ite++;
                }
            }
        }
        cout<<xorval<<'\n';
    }
}