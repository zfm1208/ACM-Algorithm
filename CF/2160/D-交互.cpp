// 律己则安，越是执着，便是越苦;
// 安下心来，看该看的风景，做该做的事。
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r)for(int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define aaa "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
double pi = acos(-1);
const int N = 2e5 + 10, mod = 1e9+7, inf = 1e18 + 5;
int get(vector<int> s){
    cout << "? " << s.size() << " ";
    for(auto x: s) cout << x << " ";
    cout << endl;
    int ans; cin >> ans;
    return ans;
}
void solve(){ 
    int n; cin >> n;
    vector<int> a(2*n+1,-1);
    vector<int> s,t;
    for(int i = 1; i <= 2*n; i++){
        s.push_back(i);
        int res = get(s);
        if(res){
            a[i] = res;
            s.pop_back();
            t.push_back(i);
        }
    }
    for(int i = 1; i <= 2*n; i++){
        if(a[i] == -1){
            t.push_back(i);
            a[i] = get(t);
            t.pop_back();
        }
    }
    cout << "! ";
    for(int i = 1; i <= 2*n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}