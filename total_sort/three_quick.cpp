#include <iostream>
#include <vector> 
#define MAXSIZE 10
using namespace std;
void swap(int nums[],int i ,int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;   
}
int medion_three(int nums[],int left,int mid ,int right){
    int l = nums[left],m = nums[mid],r = nums[right];
    if((l <= m && m <= r) || (r <= m && m <= l))
        return mid;
    if((l <= r && r <= m) || (m <= r && r <= l))
        return right;
    return left;//返回三位数的中位数;
}
int partition_three(int nums[],int left ,int right){
    int med = medion_three(nums,left,(left + right)/2,right);
    swap(nums,left,med);
    int i = left,j = right;
    while(i < j){
        while(i < j && nums[j] >= nums[left]){
            j--;
        }
        while(i < j && nums[i] <= nums[left]){
            i++;
        }
        swap(nums,i,j);
    }
    swap(nums,i,left);//将基准元素与子数组分界值交换位置;
    return i;
}

void quick_sort(int nums[],int left,int right){
        if(left >= right){
            return;
        }
        int pivot = partition_three(nums,left,right);
        quick_sort(nums,left,pivot - 1);
        quick_sort(nums,pivot + 1,right);

}

int main (){

    int arr[MAXSIZE] = {10, 7, 8, 9, 1, 5, 4, 6, 7, 9};
    quick_sort(arr,0, 9);
    for(int i = 0;i < MAXSIZE;i++){
        cout << arr[i] << " ";
    }
    return 0;
}