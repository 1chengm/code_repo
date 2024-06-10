// 包含两种I/O库，可以使用任一种输入输出方式
#include <algorithm>
#include <iostream>
using namespace std;
void print(int n);

int main()
{
    int n;
    // 请在此添加代码，输入一个各位数字不全相同的三位整数(也可以是位数或者两位数)，输出进入黑洞过程
    /********** Begin *********/
        cin >> n;
        print(n);
    /********** End **********/

    return 0;
}
int cmp1(int a,int b){
    return a<b;
}
int cmp2(int a,int b){
    return a>b;
}
int gen(int s[3]){
    int re=0;
    for(int i=0;i<3;i++)
    {
        re=re*10 + s[i];
    }
    return re;
}
int j=1;
void print(int n){
    int a[3]={0};
    int i=0;
    while(n){
        a[i++]=n%10;
        n/=10;
    }
     sort(a,a+3,cmp1);
    int min=gen(a);
    sort(a,a+3,cmp2);
    int max=gen(a);
    int temp = max- min;
if(temp==495){
        cout << j++ << ':' << max << '-' << min << '='<< max-min << endl;
     }else{
         cout << j++ << ':' << max << '-' << min << '='<< max-min << endl;
        print(temp);
     }
    
}

495 是一个很神奇的数，被称为黑洞数或者陷阱数。给定任何一个小于 1000 的正整数，经前位补 0 后可以得到一个三位数（两位数前面补 1 个 0 ，一位数前面补 2 个 0 ）。

如果这个三位数的三个数字不全相等，那么经有限次“重排求差”操作，总会得到495 。所谓“重排求差”操作即组成该数的数字重排后的最大数减去重排后的最小数。

例如，对整数 80 ，前位补 0 后得到 080 ，重排后可以得到 800 ， 008 。此时可以得到的最大数为 800 ，最小数为 008 （即 8 ）。那么需要 4 次重排求差即可得到 495 ：

1:800-8=792
2:972-279=693
3:963-369=594
4:954-459=495

本关要求对输入的一个小于 1000 且三个数字不全相等的整数，输出进入黑洞的重排求差过程。本问题又称“ Kaprekar问题 ”。