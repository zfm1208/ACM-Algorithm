#include<bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define pii pair<int, int>
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl '\n'
double pi = acos(-1);
const int N = 1e6, mod = 1e9+7, inf = 1e18 + 5;

typedef unsigned long long ULL;
const ULL P = 131;

void solve(){
    int n; cin >> n;
    vector<vector<string>> a(n+1,vector<string>(n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    if (n == 2) {
        string a12 = a[1][2];
        string a21 = a[2][1];
        if(a12.size() != a21.size()){
            cout << "NONE" << endl;
            return;
        }
        
        int len = a12.size();
        
        vector<ULL> p(len + 1, 1), hA(len + 1, 0), hB(len + 1, 0);
        for (int i = 1; i <= len; i++) {
            p[i] = p[i - 1] * P;
            hA[i] = hA[i - 1] * P + a12[i - 1]; 
            hB[i] = hB[i - 1] * P + a21[i - 1];
        }
        
        auto get_hash = [&](const vector<ULL>& h, int l, int r) -> ULL {
            return h[r] - h[l - 1] * p[r - l + 1];
        };

        int cnt = 0;
        vector<string> ans(n + 1);

        for (int i = 1; i < len; i++) {
            ULL hash_s2 = get_hash(hA, i + 1, len);
            ULL hash_b1 = get_hash(hB, 1, len - i);
            
            if (hash_s2 == hash_b1) {
                ULL hash_s1 = get_hash(hA, 1, i);
                ULL hash_b_suffix = get_hash(hB, len - i + 1, len);
                
                if (hash_s1 == hash_b_suffix) {
                    if (a12.compare(i, len - i, a21, 0, len - i) == 0 &&
                        a12.compare(0, i, a21, len - i, i) == 0) {
                        
                        cnt++;
                        if (cnt == 1) { 
                            ans[1] = a12.substr(0, i);
                            ans[2] = a12.substr(i);
                        }
                        if (cnt == 2) {
                            break; 
                        }
                    }
                }
            }
        }
        
        if (cnt == 0) cout << "NONE" << endl;
        else if (cnt == 1) cout << "UNIQUE\n" << ans[1] << "\n" << ans[2] << endl;
        else cout << "MANY" << endl; 
        return;
    }

    int l12 = a[1][2].size();
    int l13 = a[1][3].size();
    int l23 = a[2][3].size();

    if ((l12 + l13 - l23) <= 0 || (l12 + l13 - l23) % 2 != 0) {
        cout << "NONE" << endl;;
        return;
    }
    
    int len1 = (l12 + l13 - l23) / 2;
    
    if (len1 >= l12) {
        cout << "NONE" << endl;
        return;
    }    
    string s1 = a[1][2].substr(0, len1);
    vector<string> s(n + 1); 
    s[1] = s1;
    for(int i = 2; i <= n; i++){
        if(a[1][i].size() <= len1){
            cout << "NONE" << endl;
            return;
        }
        if(a[1][i].compare(0, len1, s1) != 0){
            cout << "NONE" << endl;
            return;
        }
        s[i] = a[1][i].substr(len1); 
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(a[i][j].size() != s[i].size() + s[j].size()){
                cout << "NONE" << endl;
                return;
            }
            if(a[i][j].compare(0, s[i].size(), s[i]) != 0 || 
               a[i][j].compare(s[i].size(), s[j].size(), s[j]) != 0) {
                cout << "NONE" << endl;
                return;
            }
        }
    }
    cout << "UNIQUE" << endl;
    for(int i = 1; i <= n; i++){
        cout << s[i] << endl;
    }    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}