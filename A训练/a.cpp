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

void solveA(){
    int n,k; cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end());
    int sum = 0;
    for(int i = n; i >= 1; i-=2){
        sum += a[i] - a[i-1];
    }
    if(n&1) sum -= a[1];
    int ans = max(0LL, sum - k);
    if(n&1) ans += a[1];
    cout << ans << endl;;
}
void solveC(){
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if(r1 < l2 || r2 < l1){
        cout << 1 << endl;
    }else{
        if(l1 < l2){
            if(r1 < r2){
                cout << r1 - l2 + 2 << endl;
            }else if(r1 == r2){
                cout << r1 - l2 + 1 << endl;
            }else{
                cout << r2 - l2 + 2 << endl;
            }
        }else if(l1 == l2){
            if(r1 > r2){
                cout << r2 - l1 + 1 << endl;
            }else if(r1 == r2){
                cout << r2 - l1 << endl;
            }else{
                cout << r1 - l1 + 1 << endl;
            }
        }else{
            if(r1 > r2){
                cout << r2 - l1 + 2 << endl;
            }else if(r2 == r1){
                cout << r2 - l1 + 1 << endl;
            }else{
                cout << r1 - l1 + 2 << endl;
            }
        }
    }
}
void solveD(){
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n >= 3 || (abs(a[1] - a[2]) == 1)) cout << "No" << endl;
    else cout << "Yes" << endl;
}
void solveE(){
    int n,k; cin >> n >> k;
    int ans = 0;
    n--;
    ans = n / (k-1);
    n = n % (k-1);
    if(n >= 1) ans++;
    cout << ans << endl;
}
void solveG(){
    int n; cin >> n;
    string s; cin >> s;
    string t;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            t += '1';
        }else{
            if(i == 0 || t.back() != '0') t += '0';
        }
    }
    n = t.size();
    int cnt = 0,cnt1 = 0;
    for(auto c: t){
        if(c == '0') cnt++;
        else cnt1++;
    }
    cout << (cnt1 > cnt ? "Yes" :"No") << endl;
}
void solveJ(){
    int n; cin >> n;
    vector<pii> a(n+1);
    for(int i = 1; i <= n; i++){
        int x,y; cin >> x >> y;
        a[i] = {x,y};
    }
    int cnt = 1;
    map<int,int> mp;
    mp[0]++;
    for(int i = 1; i <= n; i++){
        if(i > 1 && a[i] == a[i-1] ) continue;
        int x = min(a[i].fi, a[i].se) - max(a[i-1].fi ,a[i-1].se);
        if(mp.count(max(a[i-1].fi ,a[i-1].se)) == 0) x++;
        mp[min(a[i].fi, a[i].se)]++;
        cnt += max(0LL, x);
    }
    cout << cnt << endl;
}
void solveK(){
    int n; cin >> n;
    vector<int> a(n+1),b(n+1);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    int ans = 0;   
    map<pii,int> mp;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 0 && b[i] == 0){
            cnt++;;
        }
        if(a[i] == 0) continue;
        if(b[i] == 0){
            mp[{0,0}]++;
            continue;
        }
        int g = __gcd(a[i],b[i]);
        a[i] /= g;
        b[i] /= g;
        mp[{a[i],b[i]}]++;
    }
    for(auto[x,cn] : mp){
        ans = max(ans, cn);
    }
    cout << ans + cnt << endl;
}
void solveL(){
    int n,m; cin >> n >> m;
    vector<int> a(m+1);
    map<int,int> mp;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    auto check = [&] (int mid) -> bool {
        vector<int> b(n+1);
        int sum = 0;
        for(auto &[x,cnt] : mp){
            b[x] += min(cnt, mid);
            sum += max(0LL, cnt - mid);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            int x = mid - b[i];
            cnt += x / 2;
        }
        return cnt >= sum;
    };
    int l = 1,r = 2*m;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            r = mid - 1; 
        }else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
}
void solveH(){
    int n; cin >> n;
    int n1 = n;
    int nn = n;
    int len;
    while(nn){
        len++;
        nn /=2;
    }
    vector<int> a(100);
    for(int i = 1;i <= len;i++){
        a[i] = n & 1;
        n >>= 1;
    }
    stack<int> st; st.push(n1);
    for(int i = 1; i <= len && len != 1; i++){
        if(a[i]) st.push(n1 - (1ll << (i - 1)));
    }
    if(st.top() == 0) st.pop();
    cout << st.size() << endl;
    for(; !st.empty(); st.pop()) cout << st.top() << " ";
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        // solve();
    return 0;
}