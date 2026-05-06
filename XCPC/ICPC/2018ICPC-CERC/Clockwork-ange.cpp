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
#define ull unsigned long long

void solve(){
    string s; cin >> s;
    int ans = 0;
    int n = s.size();
    ull tar = (1ULL << n) - 1;
    ull st = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            st |= (1ULL << i);
        }
    }
    if(st == tar){
        cout << 0 << endl;
        return;
    }
    if((st & 1) == 0){
        cout << -1 << endl;
        return;
    }
    queue<array<ull,3>> q;
    q.push({st, 0ULL, 1ULL});
    while(!q.empty()){
        auto [S, dep, lk] = q.front();
        q.pop();
        ull s1 = (~S) & tar;
        int Z = __builtin_ctzll(s1);
        int ones = __builtin_popcountll(S);
        if(ones * (1ULL << (6 - dep)) < n){
            continue;
        } 
        for(int k = lk; k <= Z && k < n; k++){
            ull ns = S | ((S << k) & tar);
            if(ns == S) continue;
            if (ns == tar) {
                cout << dep + 1 << "\n";
                return;
            }
            if(dep + 1 < 6){
                q.push({ns, dep + 1, (ull)k});
            }             
        }      
    }
    cout << -1 << endl;
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