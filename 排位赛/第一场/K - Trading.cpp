#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10,mod = 1e9+7,inf = 1e18;
#define pii pair<int,int>
#define rep(i,l,r) for(int i = l; i <= r; i++)

void zfm(){
    int n; cin >> n;
    vector<pair<int,int>> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    int sum = 0;
    sort(a.begin()+1,a.end(),[](pair<int,int> x, pair<int,int> y){
        return x.first < y.first;
    });
    int l = 1,r = n;
    while(l < r){
        if(a[l].second > a[r].second){
            sum += (a[r].first - a[l].first) * a[r].second;
            a[l].second -= a[r].second;
            r--;
        }else{
            sum += (a[r].first - a[l].first) * a[l].second;
            a[r].second -= a[l].second;
            l++;
        }
    }
    cout << sum  << endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        zfm();
    }
    return 0;
}