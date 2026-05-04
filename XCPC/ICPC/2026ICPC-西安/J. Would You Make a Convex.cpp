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
    vector<int>a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end());
    int L = 0,R = 0;
    int mx = 0;
    for(int i = 2; i <= n; i++){
        int x = a[i-1], y = a[i];
        int p = n+1;
        int l = i+1,r = n;
        while(l <= r){
            int mid = (l + r) / 2;
            if(a[mid] >= x + y){
                p = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        int len = (p - i + 1);
        if(len > mx){
            mx = len;
            L = i - 1;
            R = p - 1;
        }
    }
    if(mx <= 2) cout << 0 << endl;
    else{
        cout << mx << " ";
        for(int i = L; i <= R; i++){
            cout << a[i] << " ";
        }
        cout << endl;
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