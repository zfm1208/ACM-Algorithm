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
// https://qoj.ac/contest/1071/problem/5306
void solve(){
    int n; cin >> n;
    map<string,int> mp;
    for(int i = 1; i <= n; i++)
    {
        int nn ; 
        cin >> nn;
        bool ok = 0;
        for(int q = 1; q <= nn ; q++)
        {
            int d = 0;
            string s; cin >> s;
            for(int k = 0; k < s.size(); k++){
                
                if(s.substr(k,3) == "bie"){
                    if(mp[s] == 0){
                        mp[s]++;
                        d = 1;
                        ok = 1;
                        break;
                    }
                }
            }
            if(d == 1){
                cout << s << endl;
            }
        }
        if(ok == 0){
            cout << "Time to play Genshin Impact, Teacher Rice!" << endl;
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