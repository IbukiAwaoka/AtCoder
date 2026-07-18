#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Tnum;
    cin>>Tnum;
    vector<bool>jud(Tnum,false);

    int Px,Py,Qx,Qy,Rx,Ry,Sx,Sy;

    for(int i=0;i<Tnum;i++){
        cin>>Px>>Py>>Qx>>Qy>>Rx>>Ry>>Sx>>Sy;

        int dx1=Qx-Px;
        int dy1=Qy-Py;

        int dx2=Sx-Rx;
        int dy2=Sy-Ry;

        long long cross=1LL*dx1*dy2-1LL*dy1*dx2;

        if(cross!=0){
            jud[i]=true;
        }else{
            int mx1=Px+Qx;
            int my1=Py+Qy;

            int mx2=Rx+Sx;
            int my2=Ry+Sy;

            long long dot=1LL*(mx2-mx1)*dx1+1LL*(my2-my1)*dy1;

            if(dot==0){
                jud[i]=true;
            }
        }
    }

    for(int i=0;i<Tnum;i++){
        if(jud[i]){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<'\n';
        }
    }

    return 0;
}