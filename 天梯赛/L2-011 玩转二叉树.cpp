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
/*
    给定一棵二叉树的中序遍历和前序遍历，
    请你先将树做个镜面反转，再输出反转后的层序遍历的序列。
    所谓镜面反转，是指将所有非叶结点的左右孩子对换。
    这里假设键值都是互不相等的正整数。
*/
// 中序遍历，前序遍历
vector<int> zx(35),qx(35);
// 该节点的左右子树根节点
unordered_map<int,int> cl,cr;
// 中序 [zl,zr]  前序[ql,qr]
int build(int zl, int zr, int ql, int qr) {
    if(zl > zr || ql > qr) return 0;
    int root = qx[ql];
    int k = zl;
    while(k <= zr && zx[k] != root){
        k++;
    }
    int len = k - zl;
    cl[root] = build(zl,k-1,ql+1,ql+len);
    cr[root] = build(k + 1, zr, ql + len + 1, qr);
    return root;
}
void solve(){
    int n; cin >> n;
    rep(i,1,n) cin >> zx[i];
    rep(i,1,n) cin >> qx[i];
    int root = build(1,n,1,n);
    queue<int> q;
    vector<int> ans;
    q.push(root);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.pb(cur);
        if(cr[cur] != 0) q.push(cr[cur]);
        if(cl[cur] != 0) q.push(cl[cur]);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << "\n";
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