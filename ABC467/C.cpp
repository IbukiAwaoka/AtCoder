#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tap, mods;
    cin >> tap>>mods;

    vector<long long> fis(tap);
    vector<long long> sec(tap-1);

    for (int i=0;i<tap;i++) {
        cin>>fis[i];
    }

    for (int i=0;i<tap-1;i++) {
        cin>>sec[i];
    }

    long long answer = LLONG_MAX;

    //それぞれのAに足す数字をxとしたときのその時点の最適なxを入れる．
    vector<long long> bestAdd(tap);

    // fis[0] に加える回数を全探索する
    for (int firstAdd=0;firstAdd<mods;firstAdd++) {
        vector<long long> add(tap);
        add[0]=firstAdd;

        long long total=firstAdd;

        for (int i=0;i<tap-1;i++) {
            long long nextAdd=(sec[i]-fis[i]-fis[i+1]-add[i])%mods; //次のxを決める

            if (nextAdd<0) {
                nextAdd+=mods;
            }
            add[i+1]=nextAdd;
            total+=nextAdd;
        }
        if (total<answer) {
            answer=total;
            bestAdd=add;
        }
    }
    cout<<answer<<'\n';
    return 0;
}