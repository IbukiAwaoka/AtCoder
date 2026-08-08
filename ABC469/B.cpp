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
    cin>>num;
    vector<char> St(num);
    rep(i,0,num){
        cin>>St[i];
    }
    set<int> isunashi{};
    set<int> miginashi{};
    set<int> hidarinashi{};
    rep(i,0,num){
        if(St[i]=='x') isunashi.insert(i); 
    }
    rep(i,0,num){
        if(i==num-1){
            miginashi.insert(i);
        }else if(St[i+1]=='x'){
            miginashi.insert(i);
        }
    }
    rep(i,0,num){
        if(i==0){
            hidarinashi.insert(i);
        }else if(St[i-1]=='x'){
            hidarinashi.insert(i);
        }
    }
    set<int> gaitou{};
    for(int i:isunashi){
        if(miginashi.count(i)){
            if(hidarinashi.count(i)){
                gaitou.insert(i);
            }
        }
    }
    cout<<gaitou.size()<<'\n';
    
}