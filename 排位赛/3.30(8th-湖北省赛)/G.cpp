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
// 前缀和+二分
void solve1(){
    int n,m,k; cin >> n >> m  >> k;
    string s; cin >> s;
    int len = s.size();
    s = s + s;
    int mx = 0;
    array<int,3> mp = {n,m,k};
    auto get = [&](int st) -> void {
        vector<int> a;
        for(int i = st; i+1 < 2*len; i+=2){
            if(s[i] == s[i+1]){
                if(s[i] == '1') a.pb(2);
                else a.pb(0);
            } else a.pb(1);
        }
        int sz = a.size();
        if(sz == 0) return;
        vector<vector<int>> pref(3, vector<int>(sz+1));
        for(int i = 0; i < sz; i++){
            pref[0][i+1] = pref[0][i] + (a[i] == 0);
            pref[1][i+1] = pref[1][i] + (a[i] == 1);
            pref[2][i+1] = pref[2][i] + (a[i] == 2);
        }        
        for(int r = 1; r <= sz; r++)
        {
            int le = max(1LL, r - len/2 + 1);
            int ri = r;
            int ans = r+1;
            while(le <= ri)
            {
                int mid = (le + ri) / 2;
                int c0 = pref[0][r] - pref[0][mid-1];
                int c1 = pref[1][r] - pref[1][mid-1];
                int c2 = pref[2][r] - pref[2][mid-1];
                if(c0 <= mp[0] && c1 <= mp[1] && c2 <= mp[2]){
                    ans = mid;    
                    ri = mid - 1; 
                }else{
                    le = mid + 1;
                }
            }
            if(ans <= r) mx = max(mx, 2*(r - ans + 1));
        }

    };
    get(1);
    get(0);
    cout << mx << endl;
}
// 双指针实现
void solve(){
    int n,m,k; cin >> n >> m  >> k;
    string s; cin >> s;
    int len = s.size();
    s = s + s;
    int mx = 0;
    array<int,3> mp = {n,m,k};
    auto get = [&](int st) -> void {
        vector<int> a;
        for(int i = st; i+1 < 2*len; i+=2){
            if(s[i] == s[i+1]){
                if(s[i] == '1') a.pb(2);
                else a.pb(0);
            } else a.pb(1);
        }
        array<int,3> cnt = {0,0,0};
        int l = 0;
        for(int r = 0; r < a.size(); r++){
            cnt[a[r]]++;
            while(l <= r && (mp[0] < cnt[0] || mp[1] < cnt[1] ||mp[2] < cnt[2] || (r-l+1) > len/2)){
                cnt[a[l]]--;
                l++;
            }
            mx = max(mx,2*(r-l+1));
        }
    };
    get(1);
    get(0);
    cout << mx << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve1();
    return 0;
}  