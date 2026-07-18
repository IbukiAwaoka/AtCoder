#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;
    int price,pay;
    string charg;
    int son=0;
    for(int i=0;i<num;i++){
        cin>>price>>pay>>charg;
        if(charg=="keep"){
            son+=pay-price;
        }
    }
    cout<<son<<endl;
}