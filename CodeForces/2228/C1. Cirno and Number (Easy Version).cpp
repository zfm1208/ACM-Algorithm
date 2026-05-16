#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve(){
    int a,n; cin >> a >> n;
    int d1,d2; cin >> d1 >> d2;
    if(a == 0){
        cout << min(d1,d2) << endl;
        return;
    }
    vector<int> cun;
    int tp = a;
    while(tp){
        cun.pb(tp % 10);
        tp /= 10;
    }
    reverse(cun.begin(), cun.end());
    int nn = cun.size();
    vector<int> ans;
    if(nn > 1){
        int x = 0;
        rep(i,1,nn-1) x = x * 10 + d2;
        ans.pb(x);
    }
    
    int x = 0;
    if(d1 == 0){
        x = d2;
        rep(i,1,nn) x = x * 10 + d1;
    }else{
        x = d1;
        rep(i,1,nn) x = x * 10 + d1;
    }
    ans.pb(x);
    
    int last = 0;
    for(int i = 0; i < nn; i++){
        // cout << "i: " << i << " ";
        if(cun[i] < d1){
            int x = last * 10 + d1;
            rep(j, i + 1, nn - 1) x = x * 10 + d1;
            // cout << "aaa" << x << endl;
            ans.pb(x);
        } 
        else if(cun[i] >= d1 && cun[i] < d2){
            int x = last * 10 + d2;
            rep(j, i + 1, nn - 1) x = x * 10 + d1;
            ans.pb(x);
            // cout << "bbb" << x << endl;
        }
        
        if(cun[i] > d2){
            int x = last * 10 + d2;
            rep(j, i + 1, nn - 1) x = x * 10 + d2;
            ans.pb(x);
            // cout << "ccc" << x << endl;
        } 
        else if(cun[i] <= d2 && cun[i] > d1){
            int x = last * 10 + d1;
            rep(j, i + 1, nn - 1) x = x * 10 + d2;
            ans.pb(x);
            // cout << "ddd" << x << endl;
        }

        if(cun[i] == d1 || cun[i] == d2){
            last = last * 10 + cun[i];
        }else{
            // cout << "!!!!!!!!!!!! : " << i << endl;
            break; 
        }
        if(i == nn - 1) ans.pb(last);
    }
    int res = inf;
    for(auto x : ans){
        res = min(res, abs(a - x));
    }
    cout << res << endl;
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