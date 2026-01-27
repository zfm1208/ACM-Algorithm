#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve(){
    int a[7];
    for(int i = 1; i <= 6; i++) {
        string s; cin >> s;
        a[i] = (s  ==  "true" ? 1 : 0);
    }
	int ans = (a[1]^a[4]) + (a[2]^a[5]) + (a[3]^a[6]);
	int k = a[1] + a[2] + a[3] + a[4] + a[5] + a[6];
    if(k == 2 && a[2] && ans == 0){
        cout << "7" << endl;
	}
	else if(k == 4 && a[1] && a[3] && ans == 0){
        cout << "7" << endl;
	}
	else if(ans == 0){
        cout << "8" << endl;
	}
	else if(ans == 1){
        cout << "6" << endl;
	}
	else if(ans == 2){
        cout << "5" << endl;
	}
	else{
        cout << "4" << endl;
	}
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}