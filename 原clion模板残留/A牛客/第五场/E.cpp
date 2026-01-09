#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
void solve() {
    int num = 0;
    vector<string> s(4);
    for (int i = 1; i < 4; i++) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    map<int,int> mp1, mp2;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (s[i][j] == 'X') {
                mp1[i + 10]++;
                mp1[j + 20]++;
                if (i == j) mp1[30]++;
                if (i + j == 4) mp1[40]++;
            }
            if (s[i][j] == 'G') {
                num++;
                mp2[i + 10]++;
                mp2[j + 20]++;
                if (i == j) mp2[30]++;
                if (i + j == 4) mp2[40]++;
            }
        }
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (mp2[i + 10] == 3 && mp2[j + 20] == 3) {
                cout << "Yes\n";
                return ;
            }
            if ((mp1[i + 10] + mp2[i + 10] == 3 && mp2[i + 10] != 3) ||
            (mp1[j + 20] + mp2[j + 20] == 3 && mp2[j + 20] != 3) ||
            (mp1[30] + mp2[30] == 3 && mp2[30] != 3) ||
            (mp1[40] + mp2[40] == 3 && mp2[40] != 3)) {
                cout << "Yes\n";
                return;
            }
        }
    }
    if (num == 9) cout << "Yes\n";
    else cout << "No\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}