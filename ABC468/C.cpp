#include<bits/stdc++.h>
using namespace std;

//P,Qそれぞれの辞書順の差をとるために両方とってなんやかんやする
int getRank(vector<int>numlist){
    int n=numlist.size();

    vector<int>fact(n+1,1);     //会場
    for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*i;
    }
    vector<bool>used(n+1,0);
    int rank=0;
    for(int i=0;i<n;i++){
        int smaller=0;
        for(int x=1;x<numlist[i];x++){
            if(!used[x]){
                smaller++;
            }
        }

        rank+=smaller*fact[n-i-1];
        used[numlist[i]]=1;
    }

    return rank;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tap;
    cin>>tap;

    vector<int>Plist(tap);
    vector<int>Qlist(tap);

    for(int i=0;i<tap;i++){
        cin>>Plist[i];
    }

    for(int i=0;i<tap;i++){
        cin>>Qlist[i];
    }

    int prank=getRank(Plist);
    int qrank=getRank(Qlist);
    int ans=qrank-prank-1;
    if(ans<0) ans=0;
    cout<<ans<<'\n';
}