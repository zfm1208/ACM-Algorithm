#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    string s, t; 
    cin >> s >> t;
    map<char, int> mps, mpt;
    for(auto c: s) mps[c]++;
    for(auto c: t) mpt[c]++;
    for(auto [x, y] : mps){
        if(mpt[x] < y){
            cout << "Impossible" << endl;
            return;
        }
    }
    string tp = "";
    for(auto [x, y] : mpt){
        for(int k = 0; k <  y - mps[x]; k++){
            tp += x;
        }
    }
    int n = s.size();
    vector<char> ndif(n);
    char ls = '{'; 
    for(int i = n - 1; i >= 0; i--){
        if(i + 1 < n && s[i] != s[i+1]){
            ls = s[i+1];
        }
        ndif[i] = ls;
    }
    string ans = "";
    int i = 0,j = 0;
    while(i < tp.size() && j < s.size()){
        if(tp[i] < s[j]){
            ans += tp[i];
            i++;
        }else if(s[j] < tp[i]){
            ans += s[j];
            j++;
        }else{       
            if(ndif[j] < s[j]){
                ans += s[j++];
            }else{
                ans += tp[i++];
            }
        }
    }
    while(i < tp.size()) ans += tp[i++];
    while(j < s.size()) ans += s[j++];
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}