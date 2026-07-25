#include<bits/stdc++.h>
using namespace std;

//文字列を作らずに文字から広げて数える．
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text;
    cin>>text;

    int len=text.size();
    int goodcnt=0;

    for(int center=0;center<len;center++){
        int left=center;
        int right=center;
        int miss=0;
        while(left>=0&&right<len){
            if(text[left]!=text[right]){
                miss++;
            }
            if(miss>1){
                break;
            }

            goodcnt++;

            left--;
            right++;
        }
    }
    for(int center=0;center<len-1;center++){
        int left=center;
        int right=center+1;
        int miss=0;
        while(left>=0&&right<len){
            if(text[left]!=text[right]){
                miss++;
            }
            if(miss>1){
                break;
            }
            goodcnt++;

            left--;
            right++;
        }
    }

    cout<<goodcnt<<'\n';
}