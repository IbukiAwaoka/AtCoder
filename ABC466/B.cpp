#include <bits/stdc++.h>
using namespace std;

//色ごとにサイズを格納する箱を作る
//全て-1で初期化して，出力は色の数だけにする
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num,col;
    int C_num,C_size;
    vector<int> size(101,-1);
    cin>>num>>col;
    for(int i=0;i<num;i++){
        cin>>C_num>>C_size;
        if(size[C_num]<C_size) size[C_num]=C_size;
    }
    for(int j=1;j<=col;j++){
        cout<<size[j]<<" " ;
    }
    cout<<'\n';
    return 0;
}