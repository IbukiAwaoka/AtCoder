#include <bits/stdc++.h>
using namespace std;

//先頭から順番に確かめる．先頭がiの時距離が1以下の点jまで確かめる．
//i+1からjまでは確実に1以下なのでj+1から再度確認する
int main() {
    ios::sync_with_stdio(false);

    int num;
    string ans;
    int count=0;
    int neoj=2;
    cin>>num;
    for(int i=1;i<num;i++){
        neoj = max(neoj, i + 1);
        for(int j=neoj;j<=num;j++){
            cout<<"? "<<i<<" "<<j<<endl;
            cin>>ans;
            if(ans=="Yes"){
                neoj=j+1;
            }
            else if(ans=="No") {
                break;
            }
        }
        count+=neoj-i-1;
    }
    cout<<"! "<<count<< endl ;
    return 0;
}