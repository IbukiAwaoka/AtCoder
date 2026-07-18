#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int wei,sincho;
    cin >> sincho>>wei;
    if(wei*10000>=25*sincho*sincho){
        cout<<"Yes"<<'\n';
    }else{
        cout<<"No"<<'\n';
    }
}