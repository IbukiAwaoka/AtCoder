#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int man,dist;
    cin>>man>>dist;

    vector<char>glist(man);

    for(int i=0;i<man;i++){
        cin>>glist[i];
    }

    vector<int>gpos;

    for(int i=0;i<man;i++){
        if(glist[i]=='G'){
            gpos.push_back(i);
        }
    }

    for(int i:gpos){
        for(int j=0;j<=dist;j++){
            if(i-j>=0){
                glist[i-j]='S';
            }
            if(i+j<man){
                glist[i+j]='S';
            }
        }
    }

    int count=0;

    for(int i=0;i<man;i++){
        if(glist[i]=='.'){
            count++;
        }
    }

    cout<<count<<'\n';
}