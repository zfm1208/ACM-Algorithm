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
    map<pii,vector<int>> mp;
    for(int i = 1; i <= n; i++){
        int w, h, val;
        cin >> w >> h >> val;
        if(w > h) swap(w, h);
        mp[{w,h}].pb(val);
    }
    map<pii,vector<int>> pre;
    for(auto [op,arr] :mp){
        sort(arr.begin(),arr.end(),greater<int>());
        auto [w,h] = op;
        pre[{w,h}].pb(0);
        for(int i = 0; i < mp[{w,h}].size(); i++){
            pre[{w,h}].pb(pre[{w,h}].back() + arr[i]);
        }        
    }    
    auto get = [&](int w, int h, int k) -> int {
        int cnt = min(k, (int)pre[{w,h}].size() - 1);
        if(cnt <= 0) return 0;
        return pre[{w,h}][cnt];
    };
    /*
        w X h

        3 X 3
        2 X 3
        2 X 2
        1 X 3
        1 X 2
        1 X 1
    */
    int ans = 0;
    for(int c33 = 0; c33 <= 1; c33++){
        for(int c23 = 0; c23 <= 1; c23++){
            for(int c22 = 0; c22 <= 1; c22++){
                for(int c13 = 0; c13 <= 3; c13++){
                    for(int c12 = 0; c12 <= 4; c12++){
                        int area = c33 * 9 + c23 * 6 + c22 * 4 + c13 * 3 + c12 * 2;
                        if(area <= 9){
                            int c11 = 9 - area;
                            int now = get(3, 3, c33)+ get(2, 3, c23) + get(2, 2, c22)+ get(1, 3, c13) + get(1, 2, c12)  + get(1, 1, c11);
                            ans = max(ans, now);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
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