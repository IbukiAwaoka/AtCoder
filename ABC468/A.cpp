#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;

    
    vector<int> inps;
    int inpnum;
    for (int i=0;i<num;i++){
        cin>>inpnum;
        inps.push_back(inpnum);
    }
    int count=0;
    for(int i=1;i<num-1;i++){
        if(inps[i]>inps[i-1]&&inps[i]>inps[i+1]){
            count++;
        }
    }
    /*
    for(int a:inps){
        cout<<a<<", ";
    }
    */
    cout<<count<<'\n';
}