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
int fpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
struct SegTree{
    int n;
    vector<int> tree;
    SegTree(int n){
        tree.assign(n << 2,inf);
    }

    void build(const vector<int>&a, int i, int l, int r){
        if(l == r){
            tree[i] = a[l];
        }else{
            int mid = (l + r) >> 1;
            build(a, i << 1, l, mid);
            build(a, i << 1 | 1, mid + 1, r);
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    void update(int i, int l, int r, int pos, int val){
        if(l == r){
            tree[i] = val;
        }else{
            int mid = (l + r) >> 1;
            if(pos <= mid){
                update(i << 1, l, mid, pos, val);
            }else{
                update(i << 1 | 1, mid + 1, r, pos, val);
            }
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    int query(int i, int l, int r, int tl, int tr){
        if(tl > tr) return inf;
        if(l == tl && r == tr){
            return tree[i];
        }
        int mid = (l + r) >> 1;
        return min(query(i << 1,l,mid,tl,min(tr,mid)),query(i << 1 | 1,mid+1,r,max(tl,mid+1),tr));
    }
};
/*
    给定一个区间[l,r],计算有多少整数d(0 <= d <= r-l)
    满足 min(a[l],a[l+1],...,a[l+d]) = d

    1.单点修改
    2.区间查询

    不难发现，对于一个区间[l,r]，满足条件的d最多只有一个
    f(d) = min(a[l],a[l+1],...,a[l+d]) - d = 0; 单调递减
    有单调性--解是唯一的或者没有,二分查找
    用线段树维护区间最小值
*/
void solve(){
    int n,q; cin >> n >> q;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    SegTree st(n);
    st.build(a,1,1,n);
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int id,x; cin >> id >> x;
            st.update(1,1,n,id,x);
        }else{
            // f(d) = min(a[l], a[l+1],...a[l+d]) - d = 0
            // d = mid - l;
            // 若 min_(a[l] ~ a[mid]) - (mid - l) <= 0, hight = mid - 1;
            // 则 low = mid + 1; 
            int l,r;cin >> l >> r;
            int low = l, hight = r;
            int ans = -1;
            while(low <= hight){
                int mid = (low + hight) >> 1;
                int mn = st.query(1,1,n,l,mid);
                if(mn <= mid - l){
                    hight = mid - 1;
                    ans = mid;
                }else{
                    low = mid + 1;
                }                
            }           
            if(ans != -1){
                if(st.query(1,1,n,l,ans) == ans - l){
                    cout << 1 << endl;
                }else{
                    cout << 0 << endl;
                }
            }else{
                cout << 0 << endl;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}