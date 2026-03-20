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

void solve(){
    int n,m; cin  >> n >> m;
    auto read = [&](int nn) -> string {
        string s;
        for(int i = 1; i <= nn; i++){
            int x; cin >> x;
            s = s + to_string(x);
        }
        return s;
    };
    string s = read(n);
    // cout << s << endl;
    while(m--){
        int op; cin >> op;
        if(op == 1){
            int n1; cin >> n1;
            string st = read(n1);
            int n2; cin >> n2;
            string tp = read(n2);
            if(s.find(st) != string::npos){
                s.replace(s.find(st),n1,tp);
            }
        }else if(op == 2){
            string tp = "";
            n = s.size();
            for(int i = 0; i < n; i++){
                tp += s[i];
                if((i+1 < n && s[i] + s[i+1]) % 2 == 0){
                    tp += (s[i] + s[i+1]) / 2;
                }
            }
            s = tp;
        }else{
            int l,r; cin >> l >> r;
            reverse(s.begin()+l,s.begin()+r);
        }
    }
    for(int i = 0; i < s.size(); i++){
        cout << s[i] << " ";
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