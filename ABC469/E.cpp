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

//勝率更新するか調べる
bool canAchieve(double rate,string text,int num,int needwin){
    vector<int>wincount(num+1,0);
    vector<double>ratesum(num+1,0.0);

    for(int i=0;i<num;i++){
        wincount[i+1]=wincount[i]+(text[i]=='o');

        if(text[i]=='o'){
            ratesum[i+1]=ratesum[i]+1.0-rate;
        }
        else{
            ratesum[i+1]=ratesum[i]-rate;
        }
    }
    ll addleft=0;
    double minsum=1e100;
    rep(right,1,num+1){
        while(addleft<right&&wincount[addleft]<=wincount[right]-needwin){
            minsum=min(minsum,ratesum[addleft]);
            addleft++;
        }
        if(minsum!=1e100&&ratesum[right]>=minsum){
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num,needwin;
    cin>>num>>needwin;

    string text;
    cin>>text;

    double low=0.0;
    double high=1.0;

    for(int i=0;i<70;i++){
        double mid=(low+high)/2.0;

        if(canAchieve(mid,text,num,needwin)){
            low=mid;
        }
        else{
            high=mid;
        }
    }

    cout<<fixed<<setprecision(7)<<low<<'\n';
}