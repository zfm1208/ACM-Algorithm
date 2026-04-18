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
vector<int> zx(N); // 中序遍历数组
vector<int> hx(N); // 后续遍历数组
vector<int> cl(N),cr(N);// 该节点的左/右子树的根节点
// 中序遍历的[zl,zr]  后续遍历的[hl,hr]
int build(int zl,int zr, int hl, int hr) {
    if(zl > zr || hl > hr) return 0; // 没有孩子返回0，和下面BFS判断有没有孩子一样
    int root = hx[hr];
    int k = zl;
    while(k <= zr && zx[k] != root) k++;

    /*
        中序数组就被完美劈成了两半：
        左边 [zl, k-1] 全是左家族的人
        右边 [k+1, zr] 全是右家族的人
    */

    /*
        后序数组 [hl, hr] 的排布规律
        [ --- 左子树的人 --- ] [ --- 右子树的人 --- ] [ 根 ]
    */
    int l_len = k - zl;
    cl[root] = build(zl, k-1, hl, hl+l_len-1);
    cr[root] = build(k+1, zr, hl+l_len, hr-1);
    return root;
}
// 后序遍历的顺序是“左 -> 右 -> 根”
void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> hx[i];
    for(int i = 1; i <= n; i++) cin >> zx[i];
    int root = build(1,n,1,n);
    queue<int> q; // 层序遍历 BFS
    vector<int> ans;
    q.push(root);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        if(cl[cur] != 0){
            q.push(cl[cur]);
        }
        if(cr[cur] != 0){
            q.push(cr[cur]);
        }
    }
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << (i == (int)ans.size() - 1 ? "" : " ");
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