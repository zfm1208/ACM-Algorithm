//O(n)1e8, O(n*logn)1e6, O(n*sqrt(n))1e5
//O(n^2)5e3, O(n^3)3e2, O(2^n)25, O(n!)11
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e5 + 5;
string t = "CHICKEN";
string s;
int n;
bool check(){
    for(int i = 0, j = 0; i < n ; i++){
        if(s[i] == t[j]) j++;
        if(j == t.size()) return true;
    }
    return false;
}

void solve() {
    cin >> n >> s;
    if(check()){
        vector<int> a(26,0);
        for(int i = 0; i < n; i++){
            a[s[i] - 'A']++;
        }
        for(int i = 0; i < t.size(); i++){
            a[t[i] - 'A']--;
        }
        int sum = 0,mx = 0;
        for(int i = 0; i < 26; i++){
            if(a[i] > 0){
                sum += a[i];
                mx = max(mx,a[i]);
            }
        }
        if(sum % 2 == 0 && mx <= sum / 2)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }else{
        cout << "NO" << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
