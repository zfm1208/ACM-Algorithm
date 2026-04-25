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
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    vector<int> ji,ou;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i&1) ji.pb(a[i]);
        else ou.pb(a[i]);
    }
    int cji = 0, cou = 0;
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        if(x & 1) cji++;
        else cou++;
    }
    sort(ji.begin(),ji.end(),greater<int>());
    sort(ou.begin(),ou.end(),greater<int>());
    int ans = 0;

    int pj = 0;
    if(cji && (int)ji.size()){
        pj = 1;
        for(int i = 1; i < min((int)ji.size(),cji); i++){
            if(ji[i] > 0){
                pj++;
            }else{
                break;
            }
        }        
    }
    for(int i = pj; i < (int)ji.size(); i++)
        ans += ji[i];

    int po = 0;
    if(cou && (int)ou.size()){
        po = 1;
        for(int i = 1; i < min((int)ou.size(),cou); i++){
            if(ou[i] > 0){
                po++;
            }else{
                break;
            }
        }        
    }
    for(int i = po; i < (int)ou.size(); i++)
        ans += ou[i];
        
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