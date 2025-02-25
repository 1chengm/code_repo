#include <iostream>
#define MAXSIZE 10
using namespace std;

void merge(int *nums,int left,int mid,int right){
    int tmpSize = right - left + 1;
    int *tmp = (int *)malloc(tmpSize*sizeof(int));
    //sizeof(添加的是数据类型),申请字节数;
    int i = left, j = mid + 1,k = 0;
    while(i <= mid && j <= right){
        if(nums[i] <= nums[j]){
            tmp[k++] = nums[i++];
        }else{
            tmp[k++] = nums[j++];//选择元素小的加入临时数组;
        }
    }
    while(i <= mid){
        tmp[k++] = nums[i++];
    }
    while(j <= right){
        tmp[k++] = nums[j++];
    }
    for(int k = 0; k < tmpSize;++k ){
        nums[left+k] =  tmp[k];
    }
    free(tmp);
}



void merge_sort(int *nums,int left,int right){
    if(left >= right){
        return;
    }
    int mid = left + (right - left)/2;
    merge_sort(nums,left,mid);
    merge_sort(nums,mid + 1,right);
    merge(nums,left,mid,right);
}


int main (){

    int arr[MAXSIZE] = {10, 7, 8, 9, 1, 5, 4, 6, 7, 9};
    merge_sort(arr,0, 9);
    for(int i = 0;i < MAXSIZE;i++){
        cout << arr[i] << " ";
    }
    return 0;
}