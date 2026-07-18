#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tap;
    long long mods;
    cin>>tap>>mods;

    vector<long long> fis(tap);
    vector<long long> sec(tap-1);

    for(int i=0;i<tap;i++){
        cin>>fis[i];
    }

    for(int i=0;i<tap-1;i++){
        cin>>sec[i];
    }

    // add[0]=0の場合のaddを求める
    vector<long long> add(tap);
    add[0]=0;

    for(int i=0;i<tap-1;i++){
        long long nxt=(sec[i]-fis[i]-fis[i+1]-add[i])%mods;

        if(nxt<0){
            nxt+=mods;
        }

        add[i+1]=nxt;
    }

    long long sum=0;
    long long dif=0;

    // 合計値の変化が折り返す位置を保存する
    vector<pair<long long,long long>> evt;

    for(int i=0;i<tap;i++){
        sum+=add[i];

        if(i%2==0){
            dif++;

            long long pos=mods-add[i];

            if(pos<mods){
                evt.push_back({pos,-mods});
            }
        }
        else{
            dif--;

            long long pos=add[i]+1;

            if(pos<mods){
                evt.push_back({pos,mods});
            }
        }
    }

    sort(evt.begin(),evt.end());

    // fstを全探索せず，値が折り返す位置だけを調べる
    long long ans=sum;
    long long pre=0;
    int j=0;

    while(j<(int)evt.size()){
        long long pos=evt[j].first;
        long long chg=0;

        while(j<(int)evt.size()&&evt[j].first==pos){
            chg+=evt[j].second;
            j++;
        }

        long long bef=sum+dif*(pos-pre-1);
        ans=min(ans,bef);

        sum=bef+dif+chg;
        ans=min(ans,sum);

        pre=pos;
    }

    long long lst=sum+dif*(mods-1-pre);
    ans=min(ans,lst);

    cout<<ans<<'\n';

    return 0;
}