#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;

void fff(){
    int n; cin >> n;
    vector<int> a(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin()+1,a.end());
    int ans = 0;
    int v = sum / n;
    for(int i = 1; i <= n; i++){
        if(a[i] > v){
            ans += a[i] - v;
        }
    }
    cout << ans << endl;
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