#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define int long long
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    map<char,int> mp;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
    }
    string ans;
    for(char c = 'z'; c >= 'a'; c--){
        if(mp.count(c)){
            for(int i = 1; i <= mp[c]; i++){
                ans += c;
            }
            cout << ans;
            break;
        }
    }
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