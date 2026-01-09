#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int N = 2e5 + 10;
using namespace std;
int n,m,sum = 1e9;
int pre[N];
int finds(int x){
    if(pre[x] == x) return x;
    else return pre[x] = finds(pre[x]);
}
bool vis[N];
void unions(int x,int y){
    int fax = finds(x);
    int fay = finds(y);
    if(fax != fay){
        pre[fax] = fay;
    }
}
struct node{
    int x,y,val;
}a[N];
bool cmp(node a,node b){
    return a.val < b.val;
}
bool check(int mid){
    for(int i = 1;i <= n;i ++)
        pre[i] = i;
    for(int i = 1;i <= mid;i ++){
        unions(a[i].x,a[i].y);
    }
    int cnt = 0;
    for(int i = 1;i <= n;i ++){
        if(finds(i) == i){
            cnt ++;
        }
    }
    if(cnt == 1) return true;
    return false;
}
void solve()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i ++)
        cin >> a[i].x >> a[i].y >> a[i].val;
    sort(a+1,a+m+1,cmp);
    for(int i = 1;i <= n;i ++)
        pre[i] = i;
    int l=0,r=m+1;
    sum = a[1].val;
    while(l<r){
        int mid = (l+r)>>1;
        if(check(mid)){
            r = mid;
            sum = a[mid].val;
        }else{
            l = mid + 1;
        }
    }
    bool pos =check(m);
    if(pos)cout << sum << endl;
    else cout << -1 << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}

