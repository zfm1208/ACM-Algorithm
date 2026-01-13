#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
const int mod = 1e9+7;
// struct node{
//     int l,x,r,y;
// };
void zfm(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    vector<array<int,5>> c(m+1);
    vector<vector<pair<int,int>>> b(n+1);
    for(int i = 1; i <= m; i++){
        int l,r,x,y; cin >> l >> x >> r >> y;
        c[i] = {i,l,x,r,y};
        b[l].push_back({x,i});
        b[r].push_back({x,i});
    }
    int ans = 0;
    // 按照修改值得总和排序？
    for(int i = 1; i <= n; i++){
        sort(b[i].begin(),b[i].end(),[](auto x,auto y){
            return x.first < y.first;
        });        
    }
    sort(c.begin()+1,c.end(),[](auto q,auto w){
        if(q[2] + q[4] == w[2] + w[4]){
            if(q[1] == w[1] && q[3] == w[3]){
                return q[0] < w[0];
            }else{
                if(q[1] == w[3] || q[3] == w[1]){
                    return (q > w);
                }
            }
        }
        return q[2] + q[4] < w[2] + w[4];
    });
    for(int i = 1; i <= m; i++){
        a[c[i][1]] = c[i][2];
        a[c[i][3]] = c[i][4];
    }
    for(int i = 1; i <= n; i++){
        ans += a[i];
    }
    cout << ans << endl;
    for(int i = 1; i <= m; i++){
        cout << c[i][0] << " \n"[i==m];
    }
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