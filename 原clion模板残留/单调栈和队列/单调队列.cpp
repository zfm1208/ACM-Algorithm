#include<bits/stdc++.h>
#define int long long
const int N = 3e6 + 10;
using namespace std;
int a[N];
int n,k;
struct node{
    int pos;
    int num;
};
deque<node> dq; //双端队列
void solve()
{
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    // 窗口内最大值
    for(int i = 1;i <= n;i++){
        //i 表示窗口最后一个元素
        // 如果元素，不在窗口内，需要从头弹出
        if(!dq.empty() && dq.front().pos < i-(k-1)) dq.pop_front();
        // 如果入队的元素，比队尾的元素要大，需要从队尾弹出
        while(!dq.empty() && a[i] >= dq.back().num)
        {
            dq.pop_back();
        }
        // 入队
        dq.push_back({i,a[i]});
        // 输出，队首的元素
        if(i >= k) cout << dq.front().num << " ";
    }

    // 窗口内最小值
    for(int i = 1;i <= n;i++){
        //i 表示窗口最后一个元素
        // 如果元素，不在窗口内，需要从头弹出
        if(!dq.empty() && dq.front().pos < i-(k-1)) dq.pop_front();
        // 如果入队的元素，比队尾的元素要小，需要从队尾弹出
        while(!dq.empty() && a[i] <= dq.back().num)
        {
            dq.pop_back();
        }
        // 入队
        dq.push_back({i,a[i]});
        // 输出，队首的元素
        if(i >= k) cout << dq.front().num << " ";
    }

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T = 1;
//    cin >> T;
    while(T--) solve();
    return 0;
}
//#include<bits/stdc++.h>
//#define int long long
//const int N = 2e5 + 10;
//using namespace std;
//
//void solve()
//{
//    int n,k;
//    cin >> n >> k;
//    vector<int> a(n+1),ans(n+1);
//    for(int i = 1;i <= n;i++)
//        cin >> a[i];
//    int h = 1, t = 0;
//    for(int i = 1;i <= n;i++){
//        while(t>=h && a[i] <= a[ans[t]]) t--;
//        ans[++t] = i;
//        if(ans[h] <= i-k) h++;
//        if(i >= k) cout << a[ans[h]] << " ";
//    }
//    cout << endl;
//    h = 1, t = 0;
//    for(int i = 1;i <= n;i++){
//        while(t>=h && a[i] >= a[ans[t]]) t--;
//        ans[++t] = i;
//        if(ans[h] <= i-k) h++;
//        if(i >= k) cout << a[ans[h]] << " ";
//    }
//}
//
//signed main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0),cout.tie(0);
//    int T = 1;
////    cin >> T;
//    while(T--) solve();
//    return 0;
//}



