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
    string s; cin >> s;
    if(s.size() == 1) {
        cout << s << endl;
        return;
    }
    map<char,int> mp;
    for(auto c: s) mp[c]++;
    for(int sum = 0; sum <= 900000; sum++){
        int temp = sum;
        string ans = to_string(temp);
        while(temp >= 10)
        {
            int cur = 0;
            while(temp){
                cur += temp % 10;
                temp /= 10;
            }
            ans += to_string(cur);
            temp = cur;
        }
        bool ok = 0;
        map<char,int> cnt;
        for(auto c: ans) {
            cnt[c]++;
            if(mp.find(c) == mp.end() || cnt[c] > mp[c]){
                ok = 1;
                break;
            }
        }
        if(ok) continue;
        int tot = 0;
        for(int i = 0; i <= 9; i++){
            tot += (mp[i +'0'] - cnt[i +'0']) * i;
        }
        if(tot == sum){
            for(int i = 9; i >= 0; i--){
                int count = mp[i +'0'] - cnt[i +'0'];
                while(count--){
                    cout << i;
                }
            }
            cout << ans << endl;;
            return;
        }
    }
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