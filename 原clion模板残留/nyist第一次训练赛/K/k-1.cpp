#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define endl '\n'
using namespace std;
const int N = 2e5 + 5;
int n;
vector<int>a(N);
bool check(int k){
    vector<int> b,c;
    if(k >= n) return true;
    for(int i = k + 1; i <= n; i++){
        b.push_back(a[i]);
    }
    int l = 0,r = b.size() - 1;
    while(l <= r){
        if(b[l] <= b[r]){
            c.push_back(b[l]);
            l++;
        }else{
            c.push_back(b[r]);
            r--;
        }
    }
    for(int i = 1; i < c.size(); i++){
        if(c[i] < c[i - 1]){
            return false;
        }
    }
    return true;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 0,r = n;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}