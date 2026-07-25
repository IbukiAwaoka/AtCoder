#include<bits/stdc++.h>
using namespace std;

#define MOD 998244353

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tap;
    cin>>tap;

    vector<int> numinp(tap+1);
    for(int i=1;i<=tap;i++){
        cin>>numinp[i];
    }

    //i番目のぎゃくもととそれぞれの逆元の和を保存
    vector<long long>inv(tap+1);
    vector<long long>invsum(tap+1);

    inv[1]=1;
    for(int i=2;i<=tap;i++){
        inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
    }

    for(int i=1;i<=tap;i++){
        invsum[i]=invsum[i-1]+inv[i];
        if(invsum[i]>=MOD){
            invsum[i]-=MOD;
        }
    }

    long long sum=0;
    long long ans=0;

    for(int i=1;i<=tap;i++){
        sum+=numinp[i];
        if(sum>=MOD){
            sum-=MOD;
        }

        int weight=invsum[i]-invsum[tap-i];
        if(weight<0){
            weight+=MOD;
        }

        ans=(ans+sum*weight)%MOD;
    }

    cout<<ans<<'\n';
}