#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    while(cin >> n && n != EOF){
        string s; cin >> s;
        int ans = 0;
        for(int i = 0; i < n;){
            if(s.substr(i,4) == "2020"){
                ans++;
                i+=4;
            }else{
                i++;
            }
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