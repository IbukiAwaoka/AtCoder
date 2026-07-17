#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;
    int hap;
    bool happy=true;
    for (int i=0;i<num;i++){
        cin>>hap;
        if(hap>=0)   happy=false;
    }
    if (happy)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}