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
void solve1(){
    int n, m; cin >> n >> m;
    map<int, int> mp;
    int sum_a = 0, sum_b = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        mp[x]++;
        sum_a += x;
    }
    vector<int> b(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        sum_b += b[i];
    }
    if(sum_a != sum_b) {
        cout << "No" << endl;
        return;
    }
    sort(b.begin() + 1, b.end(), greater<int>());
    int cnt = 0;
    int mx = n - m;
    auto dfs = [&](auto& self, int x) {
        if(mp[x] > 0){
            mp[x]--;
            return true;
        }
        if(x == 1) return false;
        cnt++;
        if(cnt > mx) return false;
        return self(self, x / 2) && self(self, (x + 1) / 2);
    };
    for(int i = 1; i <= m; i++){
        if(!dfs(dfs, b[i])) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
void solve(){
    int n,m; cin >> n >> m;
    priority_queue<int> pa,pb;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        pa.push(x);
    }
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        pb.push(x);
    }
    while(!pb.empty()){
        if(pa.empty()){cout << "No" << endl; return;}
        int ta = pa.top();
        int tb = pb.top();    
        if(ta == tb){
            pa.pop();
            pb.pop();
        }else if(ta < tb){
            pb.pop();
            pb.push(tb/2);
            pb.push((tb+1)/2);
        }else{
            cout << "No"<< endl;
            return;
        }
        if(pa.size() < pb.size()){
            cout << "No" << endl;
            return;
        }
    }
    if(pa.empty()){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve1();
    return 0;
}