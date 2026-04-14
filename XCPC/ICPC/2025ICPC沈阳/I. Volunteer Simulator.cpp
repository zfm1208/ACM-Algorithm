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
    int n; cin >> n;
    unordered_map<int,int> mp;
    map<pii,int> mp1;
    for(int i = 1; i <= n; i++){
        int team, id, t; 
        cin >> team >> id >> t;
        if(t < 240){
            if(mp1[{team,id}] == 0){
                cout << id << endl;
                mp[team]++;
            }else{
                cout << 0 << endl;
            }
            mp1[{team,id}]++;
        }else{
            if(mp[team] < 3){
                if(mp1[{team,id}] == 0){
                    cout << id << endl;
                    mp[team]++;
                }else{
                    cout << 0 << endl;
                }
                mp1[{team,id}]++;
            }else{
                mp1[{team,id}]++;
                mp[team]++;
                cout << 0 << endl;
            }
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