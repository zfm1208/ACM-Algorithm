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
    string s,t; cin >> s >> t;
    int n = s.size();
    int i = 0;
    for(; i < n; i++){
        if(s[i] != t[i]) break;
    }
    int j = n-1;
    for(; j >= 0; j--){
        if(s[j] != t[j]) break;
    }
    if(i > j) cout << "Y" << endl;
    else{
        // cout << i << " " << j << endl;
        reverse(s.begin()+i,s.begin()+j+1);
        // cout << s << endl;
        if(s == t) cout << 'Y' << endl;
        else cout << "N" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}