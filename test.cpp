#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N = 100010;
int nums[N];

void merge(int *nums, int left, int mid, int right){
    
    int tmpSize =  right - left + 1;
    int *temp = (int *)malloc(tmpSize * sizeof(int));
    int j = mid + 1, i = left, k = 0;//j取中间值，开始二路归并;
    while(i <= mid && j <= right){
        if(nums[i] <= nums[j]){
            temp[k++] = nums[i++];
        }else temp[k++] = nums[j++];//从小到大;
    }
    while(i <= mid) temp[k++] = nums[i++];//i还有剩余元素;
    while(j <= right) temp[k++] = nums[j++];
    for(int k = 0; k < tmpSize; ++k){
        nums[left + k] == temp[k];//从左到右排序后归并;
    }
    free(temp);
}

void merge_sort(int *nums, int left, int right){
    //递归出口;
    if(right <= left) return;
    int mid = left + (right - left)/2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    
    merge(nums,left, mid, right);
}



int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> nums[i];
    merge_sort(nums, 0, n - 1);
    for(int i = 0; i < n; i++) cout << nums[i] << " ";
    
    return 0;
}