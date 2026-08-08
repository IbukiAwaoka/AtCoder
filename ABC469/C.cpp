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
    vector<char> fukuro(num);
    rep(i,0,num){
        cin>>fukuro[i];
    }
    /*
    int caneat=0;
    //num回やる
    rep(l,1,num+1){
        //まずl個袋から取り出す
        caneat=l;
        int nowOK=0;
        int newOK=0;    
        rep(i,0,l){
            if(fukuro[i]=='o')
            nowOK++;
        }
        //l個目以降でnowOK個食べるのを繰り返す
        while(nowOK>0){
            //今の数で最後まで食べられるならループ終了
            if(caneat+nowOK>num){
                caneat=num;
                break;
            }else{
                int couldeat=caneat;
                caneat+=nowOK;
                rep(i,couldeat,caneat){
                    if(fukuro[i]=='o')
                    newOK++;
                }
                nowOK=newOK;
                newOK=0;

            }
    }*/
    vector<int>osum(num+1,0);
    rep(i,0,num){
        osum[i+1]=osum[i];
        if(fukuro[i]=='o'){
            osum[i+1]++;
        }
    }
    rep(l,1,num+1){
        int caneat=l;

        int nowOK=osum[l]-osum[0];

        while(nowOK>0){
            if(caneat+nowOK>num){
                caneat=num;
                break;
            }
            int couldeat=caneat;
            caneat+=nowOK;
            int newOK=osum[caneat]-osum[couldeat];
            nowOK=newOK;
        }

        cout<<caneat<<'\n';
    }
}