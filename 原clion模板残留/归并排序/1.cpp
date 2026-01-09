//归并排序
#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int a[N] ,b[N];//b为辅助数组

/**
* 对a数组中[l,r]区间内的元素进行排序
*
* @param l 区间左边界，闭区间
* @param r 区间右边界，闭区间
*/
void merge_sort(int l , int r)
{
    // 如果整个区间中元素个数大于1，则继续分割
    if(r-l > 0)
    {
        int mid = (l+r) / 2;
        // 1、划分为2个尽可能相等的区间并排序
        merge_sort(l , mid);
        merge_sort(mid+1 , r);

        // printf("%d-%d  %d-%d\n",p,mid ,q ,r);

        // 2、将2个有序的序列进行合并
        int i = l; // 辅助数组的下标
        int p = l , q = mid+1; // p、q指针分别指向2个有序序列的首个元素
        while(p<=mid || q<=r) //左右两部分只要有一部分不为空，就还需循环
        {
            if(q>r || (p<=mid && a[p]<=a[q])) // 从左半数组复制到辅助数组后p指针后移
                b[i++] = a[p++];
            else b[i++] = a[q++]; // 从右半数组复制到辅助数组后q指针后移
        }

        // 3、将辅助数组b中排好序的元素复制到a中，即a中[l,r]区间内的元素已经有序
        for(i = l ; i <= r; i++)
            a[i] = b[i];
    }
}

int main()
{
    int n;
    while(cin >> n)
    {
        for(int i = 1 ; i <= n; i ++)
            cin >> a[i];
        merge_sort(1 , n);
        for(int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}