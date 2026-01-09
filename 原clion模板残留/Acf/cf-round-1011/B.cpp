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
const int N = 2e5 + 5;
//先没有 0 的全选
//最左边不为0的 先选 [2,n] 再选 [1,2]
//最右边不为0的 先选 [1,n-1] 再选 [1,2]
//左右两边均为 0 的 先选 [3,n] 再选 [1,2] 再选 [1,2]
void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    map<int,int> mp;
    rep(i,1,n) mp[a[i]]++;
    if(mp[0] == 0){
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return;
    }
    if(mp[0] == n){
        cout << 3 << endl;
        cout << n-1 << " " << n << endl;
        cout << 1 << " " << n-2 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }
    if(a[1] != 0 && mp[0]!=0){
        cout << 2 << endl;
        cout << 2 << " " << n << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }
    if(a[n] != 0 && mp[0]!=0){
        cout << 2 << endl;
        cout << 1 << " " << n-1 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }
    int pos = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] != 0){
            pos = i;
            break;
        }
    }
    if(mp[0] == pos-1){
        cout << 3 << endl;
        cout << 1 << " " << pos-1 << endl;
        cout << 1 << " " << n-pos+2 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }else if(mp[0] != pos-1 && pos !=2){
        cout << 3 << endl;
        cout << pos << " " << n << endl;
        cout << 1 << " " << pos-1 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }

    cout << 3 << endl;
    cout << pos+1 << " " << n << endl;
    cout << 1 << " " << pos << endl;
    cout << 1 << " " << 2 << endl;
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
