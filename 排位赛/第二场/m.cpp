#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;


void fff(){
    int n,k; cin >> n >> k;
    while(k--){
        int tp = n/2;
        n = n - tp;
        if(n <= 1) break;
    }
    cout << n << endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        fff();
    }
    return 0;
}