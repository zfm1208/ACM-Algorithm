#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 1e6 + 5;
int nexts[N];
string s, t;
void find_sub_string (){
    int j = 0;
    nexts[0] = 0;
    for(int i = 1; i <= t.size(); i++){
        while(j > 0 && t[i] != t[j]) j = nexts[j - 1];
        if(t[i] == t[j]) j++;
        nexts[i] = j;
    }
}
void solve() {
    cin >> s >> t;
    find_sub_string();
    int j = 0;
    for(int i = 0; i < s.size(); i++){
        while(j > 0 && s[i] != t[j]) j = nexts[j - 1];
        if(s[i] == t[j]) j++;
        if( j == t.size()) cout << i - t.size() + 1 + 1 << endl;
    }
    for(int i = 0; i < t.size(); i++){
        cout << nexts[i] << " ";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
