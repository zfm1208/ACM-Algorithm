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
// https://qoj.ac/contest/2641/problem/14950

/*
    题意：
    平面上有 n 只青蛙，初始坐标已知，第一只被激活的青蛙编号为 s。
    每次被激活的青蛙可以跳过另一只青蛙，落点为中心对称点。落地后，被跳过的那只青蛙被激活。
    已知经过若干次跳跃后所有青蛙的最终坐标，求最后一只被激活（停在原地）的青蛙编号。

    思路 (寻找系统不变量)：
    1. 核心推导：假设青蛙 A 被激活，跳过了青蛙 B。
       根据中心对称公式，A 的新坐标 A' = 2B - A。
    2. 观察坐标总和 Sum 的变化：
       跳跃后的新总和 Sum' = Sum - A + A' = Sum - A + (2B - A) = Sum + 2B - 2A。
    3. 发现守恒定律：
       把上式移项：Sum' - 2B = Sum - 2A。
       在跳跃前，激活的是 A；在跳跃后，激活的是 B。
       这说明：【所有青蛙坐标总和 - 2 * 当前激活青蛙的坐标】是一个永远不变的常数！
    4. 终极公式：
       让初始状态 = 最终状态：
       Sum_P - 2 * P_s = Sum_Q - 2 * Q_t
       解方程得到最后一只青蛙的终点坐标：
       Q_t = P_s + (Sum_Q - Sum_P) / 2
    5. 实现细节：
       分别对 x 轴和 y 轴应用上述公式，算出目标坐标，然后遍历一遍 Q 数组找到对应编号即可。
       时间复杂度 O(N)，完美绕过繁琐的跳跃模拟。
*/
struct node {
    int x, y;
};
void solve(){
    int n,s; cin >> n >> s;
    vector<node> p(n+1), q(n+1);
    int sump_x = 0,sump_y = 0;
    int sumq_x = 0,sumq_y = 0;
    for(int i = 1; i <= n; i++){
        cin >> p[i].x >> p[i].y;
        cin >> q[i].x >> q[i].y;
        sump_x += p[i].x;
        sump_y += p[i].y;
        sumq_x += q[i].x;
        sumq_y += q[i].y;
    }
    int x = p[s].x + (sumq_x - sump_x) / 2;
    int y = p[s].y + (sumq_y - sump_y) / 2;
    for(int i = 1; i <= n; i++){
        if(q[i].x == x && q[i].y == y){
            cout << i << endl;
            return;
        }
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