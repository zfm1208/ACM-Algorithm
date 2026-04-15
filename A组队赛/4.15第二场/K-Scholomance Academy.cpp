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
struct node {
    char c;
    int x;
    bool operator<(const node& other) const {
        return x > other.x; 
    }
};

/*
    P 正类 
    N 负类
    T 模型猜对了
    F 模型猜错了

    预测分数 >= 0 : 就是机器觉得你是+, 所以产生了 TP / FP
    预测分数 <  0 : 就是机器预测你是-, 所以产生了 TN / FN

    TPR = TP / P 

    8  阀值 30
    + 34  TP
    + 33  TP
    + 26  FN
    - 34  FP
    - 38  FP
    + 39  TP
    - 7   TN
    - 27  TN

    TP : 3 FN : 1
    FP : 2 TN : 2

    P = TP + FN = 4
    M = TN + FP = 4

    TPR = TP / P = 0.75
    FPR = FP / M = 0.5
    
*/

/*
    ! 题意:
    题目给了 n 个样本, 每个样本有 2 个属性
    (1): 真实标签 + : (正类)，  - : (负类)
    (2): 预测分数 代表模型认为它是正类的可能性

    题目让我们算一个叫 AUC 的值
    我们通过观察图像和公式，可以推出来就是
    在一个坐标系中, X 轴是FPR (从0到1), Y 轴是TPR(从0到1)
    ! FPR: 
        FPR = FP / (FP + TN)
        分母TN + FP是什么？
        TN: 模型预测对的负样本 
        FP: 模型预测错的负样本
        TN + FP 是数据集里面 "负样本的总个数" 记为 M
        FPR = FP / M
    X 轴代表 FPR ,当 阀值 X 从大往小降,
    恰好遇到一个负样本的分数时, 这个负样本就被模型错误的预测成了正类    
    这时候 FP 的数量就 + 1
    FPR 增加 1 / M

    ! TPR :
        TPR = TP / (TP + FN)
        同理 TPR = TP / P
        TP: 被正确预测为正类的正样本的数量(分数> 当前阀值 的正样本的数量)

    ! AUC = f (1,0) ROC 曲线 dr
    对一个图像求积分，其实就是把它切成无数个小矩形，然后把他们的面积加起来
    但因为这一题的样本个数是有限的(离散的), 所以曲线不是一条光滑的弧线，而是一条阶梯状的折线
    AUC = (每一个矩形的宽度 * 对应的高度)

    * 我们从(0,0) 开始画线
    * 我们把所有样本的分数从大到小排好队
    * 我们拿着一个阈值X从最大的分数开始,一点点往下降低
    * 每遇到一个正样本+: 我们在图上往上画一格
    * 每遇到一个负样本-: 我们在图上往右画一格
    * 最后让求的就是这条线与X轴围成的面积
    * 
    ! 我们来看看面积是怎么产生的:
    (1) 往上走（遇到正样本）：只增加高度，不产生面积。

    (2) 往右走（遇到负样本）：产生了一个矩形面积！

    这个矩形的宽是 1 格（准确地说是 1 / 负样本总数）
    这个矩形的高是多少？
    就是你现在已经往上走了多少格，也就是比当前负样本分数高的正样本数量！

    ! 双指针算法思路
    既然问题变成了“找有多少个正样本的分数 > 负样本的分数”，
    如果每次都暴力去数，肯定超时

    我们建两个数组：pos 专门存正样本分数，neg 专门存负样本分数。
    把它们都从小到大排序。
    我们遍历每一个负样本 neg[i]，然后用一个指针 j 去正样本数组 pos 里找。
    因为 pos 已经从小到大排好序了，只要 pos[j] <= neg[i]，指针 j 就一直往右走。

    当 pos[j] > neg[i] 时，停下来。重点来了：因为数组是有序的，既然当前的 pos[j] 大于负样本，那么 j 后面的所有正样本肯定也都大于这个负样本！

    所以，对于这个负样本，比它大的正样本数量直接就是：pos 数组的总长度 - 当前的指针位置 j。
*/
void solve() {
    int n; cin >> n;
    vector<int> pos; 
    vector<int> neg;
    for (int i = 0; i < n; i++) {
        string s; int score;
        cin >> s >> score;
        if(s[0] == '+') {
            pos.push_back(score);
        }else{
            neg.push_back(score);
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    int sum = 0;
    int j = 0; 
    for (int i = 0; i < neg.size(); i++) {
        while (j < pos.size() && pos[j] <= neg[i]) {
            j++;
        }
        sum += pos.size() - j;
    }
    int total_P = pos.size();
    int total_N = neg.size();
    double ans = (double)sum / ((double)total_P * total_N);
    cout << fixed << setprecision(10) << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T; 
    while(T--)
        solve();
    return 0;
}