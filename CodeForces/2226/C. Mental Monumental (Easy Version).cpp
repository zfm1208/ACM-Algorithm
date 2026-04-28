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
/*
6 % 1 = 0
6 % 2 = 0
6 % 3 = 0
6 % 4 = 2 0 ~ (6-1)/2
6 % 5 = 1
6 % 6 = 0

7 % 1 = 0
7 % 2 = 1
7 % 3 = 1
7 % 4 = 3  0 ~ (7-1)/2
7 % 5 = 2
7 % 6 = 1
7 % 7 = 0

9 % 1 = 0
9 % 2 = 1
9 % 3 = 0
9 % 4 = 1
9 % 5 = 4   0 ~ (9-1)/2
9 % 6 = 3
9 % 7 = 2
9 % 8 = 1
9 % 9 = 0

10 % 1 = 0
10 % 2 = 0
10 % 3 = 1
10 % 4 = 2
10 % 5 = 0
10 % 6 = 4   0 ~ (10-1)/2
10 % 7 = 3
10 % 8 = 2
10 % 9 = 1
10 % 10 = 0


    a[i] -> (0 ~ (a[i]-1)/2)
    a[i] -> a[i]
*/
void solve(){
    // for(int i = 1; i <= 6; i++){
    //     cout << 6 << " % " << i << " = ";
    //     cout << 6 % i << endl;
    // }

    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end());
    int ans = 0;
    int l = 0, r = n;
    auto check = [&] (int x) -> bool {
        vector<int> vis(n+1);
        vector<int> cun;
        for(int i = 1; i <= n; i++){
            if(a[i] < x && vis[a[i]] == 0){
                vis[a[i]] = 1;
            }else{
                if(a[i]) cun.pb((a[i] - 1) >> 1);
                else cun.pb(-inf);
            }
        }
        int p = 0;
        for(int i = 0; i < x; i++){
            if(vis[i] == 1) continue;
            while(p < cun.size() && cun[p] < i) p++;
            if(p == cun.size()) return false;
            p++;
        }
        return true;
    };
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else {
            r = mid - 1;
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