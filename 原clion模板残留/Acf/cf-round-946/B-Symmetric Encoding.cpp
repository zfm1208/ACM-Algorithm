#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N = 2e5 + 10;
using namespace std;
void solve()
{
    int n;cin >> n;
    string s;cin >> s;
    bool f[300] = {0};
    for (auto & i : s)
        if (!f[i]) f[i] = 1;
    string r;
    for (int i = 0; i < 300; i ++ ) if (f[i]) r += (char)i;
    map<char, char> mp;
    for(int i = 0; i < r.size(); i++){
        mp[r[i]] = r[r.size() - i - 1];
    }
    for(int i = 0; i < s.size(); i++)
        cout << mp[s[i]];
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}

