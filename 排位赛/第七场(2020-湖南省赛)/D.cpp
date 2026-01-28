#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
    abcabc -> abc
    abcabcabcabc
    abcabc
       abcabc
          abcabc
*/
void solve(){
    int n;
    while(cin >> n){
        map<string,int> mp;
        for(int i = 1; i <= n; i++){
            string s; cin >> s;
            string t = s + s;
            int pos = t.find(s,1);
            mp[s.substr(0,pos)]++;
        }
        int ans = 0;
        for(auto [_,x]: mp){
            ans += x*(x-1)/2;
        }
        cout << ans << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1; 
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}