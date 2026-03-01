#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    string a,b; cin >> a >> b;
    if(a==b){
        cout << a << '='<< b << endl;
    }
    else if(a > b){
        cout << a << ">" << b << endl;
    }else{
        cout << a << "<" << b << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}