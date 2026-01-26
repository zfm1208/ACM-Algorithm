#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)
void solve(){
    int n = 5;
    int sum1 = 0, sum2 =0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        sum1+=x;
    }
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        sum2+=x;
    }
    if(sum2 > sum1){
        cout << "Red";
    }else{
        cout << "Blue";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}