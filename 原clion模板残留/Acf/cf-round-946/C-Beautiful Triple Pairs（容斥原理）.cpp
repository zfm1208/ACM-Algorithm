#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long

void solve(){
    int n;cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    map<pii,int>m1, m2, m3;
    map<pair<pii,int>,int>m4;
    long long res = 0;
    for(int i = 1;i <= n-2;i++){
        res += (m1[{a[i],a[i+1]}] + m2[{a[i],a[i+2]}] + m3[{a[i+1],a[i+2]}] - (ll)3 * m4[{{a[i],a[i+1]},a[i+2]}]);

        m1[{a[i],a[i+1]}]++;
        m2[{a[i],a[i+2]}]++;
        m3[{a[i+1],a[i+2]}]++;
        m4[{{a[i],a[i+1]},a[i+2]}]++;
    }
    cout << res << endl;
}

int main(){
    int T;cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
