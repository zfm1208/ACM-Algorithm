#include<bits/stdc++.h>
using namespace std;
#define intg long long


void solve(){
    int x,y; cin >> x >> y;
    int a,b,c;
    if(y % 500 != 0){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; ; i++){
        for(int j = 0; ; j++){
            if(i + j > x) break;
            if(1000*i + 2500*j > y) break;
            if(y == 1000*i + 2500*j){
                cout << x-i-j << " " << i << " " << j << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}