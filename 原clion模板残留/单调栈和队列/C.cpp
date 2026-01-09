#include<bits/stdc++.h>
#define int long long
const int N = 2e5 + 10;
using namespace std;
struct node{
    int pos,val;
};
deque<node> dq;
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1),cun(m+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    int l = 0,r = 0,ans = 1e9;
    for(int i = 1; i <= n; i++){
        if(cun[a[i]] == 0) cnt++;
        dq.push_back({i,a[i]});
        cun[a[i]]++;
        while(!dq.empty() && cun[a[dq.front().pos]] > 1) {
            cun[a[dq.front().pos]]--;
            dq.pop_front();
        }
        if(cnt == m){
            if(dq.size() < ans){
                ans = dq.size();
                l = dq.front().pos;
                r = dq.back().pos;
            }
        }
    }
    cout << l << " " << r << endl;


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}

