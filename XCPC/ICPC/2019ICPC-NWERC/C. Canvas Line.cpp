// 律己则安，越是执着，便是越苦;
// 安下心来，看该看的风景，做该做的事。
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define se second
#define fi first
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

void solve() {
    int n; cin >> n;
    vector<pii> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    int k; cin >> k;
    vector<int> c(n+1);
    map<int,int> mp;
    while(k--){
        int x; cin >> x;
        for(int i = 1; i <= n; i++){
            if(a[i].first <= x && x <= a[i].second){
                c[i]++;
            }
        }mp[x]++;
    }
    for(int i = 1; i <= n; i++){
        if(c[i] >= 3){
            cout << "impossible\n";
			return ;
        }
    }
	vector<int> ans;
	for(int i = 2; i <= n; i++){
		if(c[i] <= 1 && c[i-1] <= 1 && !mp.count(a[i].first) && a[i].first == a[i-1].second){
			c[i-1]++;
			c[i]++;
			ans.push_back(a[i].first);
		}
	}
	for(int i = 1; i <= n; i++){
		if(c[i] == 2){
			continue;
		}
		for(int j = a[i].first + 1; j < a[i].second && c[i] < 2; j++){
			if(mp.count(j))continue;
			c[i]++;
			ans.push_back(j);
		}
	}
	cout << ans.size() << '\n';
    for(auto &x: ans){
        cout << x << " ";
    }cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}