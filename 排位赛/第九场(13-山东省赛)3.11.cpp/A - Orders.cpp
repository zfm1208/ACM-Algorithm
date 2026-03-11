#include<bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
void solve(){
    int n,k; cin >> n >> k;
    vector<pii> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin()+1,a.end(),[](pii x, pii y){
        if(x.first == y.first) return x.second < y.second;
        return x.first < y.first;
    });
    a[0].first = a[1].first;
    int sum = a[1].first * k;
    for(int i = 1; i <= n; i++){
        sum += (a[i].first - a[i-1].first) * k;
        sum -= a[i].second;
        if(sum < 0){
            cout << "No"<< endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}