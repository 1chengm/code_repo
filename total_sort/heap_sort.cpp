#include <iostream>
#define MAXSIZE 10
using namespace std;
void swap(int nums[],int i ,int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp; 
}
/* 堆的长度为 n ，从节点 i 开始，从顶至底堆化 */
void sift_down(int nums[],int n,int i){
    
    while(1){
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int ma = i;
        if(l < n && nums[l] > nums[ma]) ma = l;
        if(r < n && nums[r] > nums[ma]) ma = r;
        if(ma == i) break;
        swap(nums,i,ma);
        i = ma;
    }
}
//堆排序
void heap_sort(int nums[],int n){
    for(int i = n/2 -1;i >= 0;i--){
        sift_down(nums,n,i);//建造堆;
    }
    //从堆中提取最大元素，循环n - 1轮；
    for(int i = n - 1;i > 0;i--){
        swap(nums,0,i);
        sift_down(nums,i,0);
    }
}
int main (){

    int arr[MAXSIZE] = {10, 7, 8, 9, 1, 5, 4, 6, 7, 9};
    heap_sort(arr, MAXSIZE);
    for(int i = 0;i < MAXSIZE;i++){
        cout << arr[i] << " ";
    }
    return 0;
}