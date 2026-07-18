#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> R(M), C(M);     //m買い目に操作した行，列をそれぞれ記録
    vector<int> lastRow(N, -1); //各行で最後に操作したのが五日を記録
    vector<int> lastCol(N, -1);

    for (int i = 0; i < M; i++) {
        cin >> R[i] >> C[i];
        //0始まりにする
        R[i]--;
        C[i]--;

        lastRow[R[i]] = i;
        lastCol[C[i]] = i;
    }

    int ans = 0;

    for (int i = 0; i < M; i++) {
        if (lastRow[R[i]] == i && lastCol[C[i]] == i) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}