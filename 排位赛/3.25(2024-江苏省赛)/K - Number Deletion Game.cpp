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
    一开始有n个数
    Alice 和 Bob, 每局可以选一个最大的数x,然后删掉x,
    并选择一个小于x的y，添加1,2,3,..., y。 如果选择x = 1，则不用添加
    问谁最后选的最后一个数，谁就赢。

    Anser: 最大值的个数是奇数那Alice赢,反之Bob赢
    Solution:
    我们知道，对于最大值，如果对方选择x,并添加1-y,轮到我们时我们也可以选择和对方一样的操作
    来抵消操作
    但再出完牌之后怎么保证对方是必输态呢？
    在下局轮到对方时,我们要保证对方 此时的最大值个数为偶数, 这样的话最后一步的操作还是我们来决定
    

    如果一开始最大值个数为偶数，那么alice操作后，我们做alice同样的操作，来抵消掉
    这样最后一步就轮到我们来了，那么我们看看下一个最大值的个数，如果是偶数的话，那我们就选择y=0,
    否则如果是奇数，我们就选择下一个最大值，使得下一个最大值的个数永远为偶数，这样的话，下一个最大值最后一次操作还是我们进行

    如果一开始最大值个数为奇数，Alice可以把最大值变成0，那么此时变成了Bob先手，又回到了第一种情况，此时Alice总能保证自己最后能赢
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n+1);
    int mx = 0, cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] > mx) mx = a[i],cnt = 1;
        else if(a[i] == mx) cnt++;
    }
    cout << ((cnt & 1) ? "Alice" : "Bob") << endl;
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