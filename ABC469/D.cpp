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

void addPair(set<pair<int,int>>&ansset,int x,int y){
    if(x==y){
        return;
    }
    if(x>y){
        swap(x,y);
    }
    ansset.insert({x,y});
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll num,game;
    cin>>num>>game;

    vl Alist(game);
    vl Blist(game);

    for(int i=0;i<game;i++){
        cin>>Alist[i]>>Blist[i];
    }

    if(game==0){
        ll ans=num*(num-1)/2;
        cout<<ans<<'\n';
        return 0;
    }

    set<pair<int,int>>ansset;
    vl candlist={Alist[0],Blist[0]};

    for(int cand:candlist){
        vl otherlist;
        bool norestrict=true;

        for(int i=0;i<game;i++){
            int a=Alist[i];
            int b=Blist[i];

            if(a==cand||b==cand){
                continue;
            }

            if(norestrict){
                otherlist.push_back(a);
                otherlist.push_back(b);
                norestrict=false;
            }
            else{
                vl nextlist;

                for(int x:otherlist){
                    if(x==a||x==b){
                        nextlist.push_back(x);
                    }
                }

                sort(nextlist.begin(),nextlist.end());
                nextlist.erase(unique(nextlist.begin(),nextlist.end()),nextlist.end());

                otherlist=nextlist;
            }
        }

        if(norestrict){
            rep(other,1,num+1){
                addPair(ansset,cand,other);
            }
        }else{
            for(int other:otherlist){
                addPair(ansset,cand,other);
            }
        }
    }

    cout<<ansset.size()<<'\n';
}