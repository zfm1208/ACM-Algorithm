#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;
const int N = 2e6 + 5;
const int seed = 233;
ull ha[N],ha1[N],p[N];
string t,s;
void init(){
    p[0] = 1;
    for(int i = 1; i < N; i++){
        p[i] = p[i - 1] * seed;
    }
}
void solve() {
    init();
    cin >> t;
    int len1 = t.size();
    t = ' ' + t + t;
    int len2 = t.size();
    set<ull> st;
    ha[0] = 0;
    for(int i = 1; i < len2; i++){
        ha[i] = (ha[i - 1] * seed + t[i] - 'a') ;
    }
    int j = 1;
    for(int i = len1; i < len2; i++){
        st.insert((ha[i] - ha[j - 1] * p[i - j + 1] ));
        j++;
    }
    int n; cin >> n;
    while(n--){
        cin >> s;
        s = ' ' + s;
        int cnt = 0;
        ha1[0] = 0;
        int len = s.size();
        for(int i = 1; i < len; i++) {
            ha1[i] = (ha1[i - 1] * seed + s[i] - 'a');
        }
        int j = 1;
        for(int i = len1; i < len; i++){
            if(st.count((ha1[i] - ha1[j - 1] * p[i - j + 1]))) cnt++;
            j++;
        }
        cout << cnt << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}
