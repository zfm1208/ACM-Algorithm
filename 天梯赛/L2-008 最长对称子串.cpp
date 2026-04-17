#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    string s; getline(cin,s);
    int ans = 1;
    int n = s.size();
    auto check = [&] (int l, int r) -> bool {
        string s1 = s.substr(l,r-l+1);
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        return s2 == s1;
    };
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(check(i,j)){
                ans = max(ans, j-i+1);
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}