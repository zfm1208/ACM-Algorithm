#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
bool check(int n){
    int op = n % 10;
    // cout << "op: " << op << endl;
    while(n >= 10){
        n/=10;
        // cout << n%10 << endl;
        if(n % 10 != op) return false;
    }
    return true;
}
void solve(){
    int mx = 20255202;
    int ans = 0;
    for(int i = 1;; i++){
        int sum = i * 10 + 45;
        if(sum > mx) break;
        // cout << sum << endl;
        if(check(sum)){
            ans += sum;
        }
        // return;
    }
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}