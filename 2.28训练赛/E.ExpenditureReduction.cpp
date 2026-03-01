#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i = l; i <= r; i++)
void solve(){
    string s,t; cin >> s >> t;
    int n = s.size();
    int nt = t.size();
    int i = 0; // S 指针
    int pt = 0; // t 指针
    string ans = "";
    int mx = 1e6;
    while(i < n){
        pt = 0;
        int r = i;
        while(r < n && pt < nt){
            if(s[r] == t[pt]){
                pt++;
            }
            if(pt == nt) break;
            r++;
        }
        if(pt < nt) break;
        int l = r;
        pt = nt - 1;
        while(pt >= 0 && l >= 0){
            if(s[l] == t[pt]){
                pt--;
            }
            if(pt < 0) break;
            l--;
        }
        int len = r - l + 1;
        if(len < mx){
            mx = len;
            ans = s.substr(l,len);
        }
        i = l + 1;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}