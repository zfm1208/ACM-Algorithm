#include<bits/stdc++.h>
using namespace std;
#define int long long
// 每个子弹上海b
// 射速r
// 造成总伤害d
// 射击时间s
void solve(){
    int b,r,d,s; cin >> b >> r >> d >> s;
    if(r == 0){
        if(d > 0){
            cout << "gua!" << endl;
        }else{
            cout << "ok" << endl;
        }
        return;
    }
    int op = s * r / 60 + 1;
    if(d > op * b){
        cout << "gua!"<< endl;
    }else{
        cout << "ok" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}