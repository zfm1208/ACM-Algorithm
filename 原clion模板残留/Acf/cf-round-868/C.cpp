//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i = l; i <= r; i++)
#define per(i,l,r) for(int i = l; i >= r; i--)
#define ull unsigned long long
#define pii pair<int,int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define debug cout << "-----------------------------" << endl;
const int mod1 = 1e9 + 7,mod2 = 998244353,inf = 0x3f3f3f3f;
const int N = 1e7 + 5;
int vis[N];
vector<int> prime;
void eular(){
    for(int i = 2; i < N; i++){
        if(!vis[i]) prime.pb(i);
        for(auto j : prime){
            if(i * j > N) break;
            vis[i * j] = 1;
            if(i % j == 0) break;
        }
    }
}
void solve() {
    int n; cin >> n;
    unordered_map<int,int> mp;
    int x;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(vis[x] == 0){
            mp[x]++;
            continue ;
        }
        for(int i = 2;i * i <= x;i ++ ){
            if(x % i == 0 && vis[i] == 0){
                while(x % i == 0){
                    x /= i;
                    mp[i] ++ ;
                }
            }
        }
        if(x != 1) mp[x]++;
    }
    int ans = 0;
    int cnt = 0;
    for(auto &i : mp){
        ans += i.second / 2;
        cnt += i.second % 2;
    }
    cout << ans + cnt / 3 << endl;
    mp.clear();
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    eular();
    cin >> T;
    while (T--) solve();
    return 0;
}
