#include <iostream>
#include <vector> 
using namespace std;
void swap(vector<int> & nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int partion(vector<int> & nums,int left,int right){
    int i = left;
    int j = right;
    while(i < j){
        while (i < j && nums[j] >= nums[left]) j--;
        while(i < j && nums[i] <= nums[left]) i++;
        swap(nums,i,j);
    }
    // 将基准数交换至两子数组的分界线
    swap(nums, i, left);
    // 返回基准数的索引
    return i;
}
void quick_sort(vector<int> & nums,int left,int right){
        if(left >= right) return;
        int pivot = partion(nums,left,right);//哨兵划分;
        quick_sort(nums,left,pivot-1);
        quick_sort(nums,pivot +1,right);
}

int main (){

    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quick_sort(arr,0,arr.size() - 1);
    for(int i = 0;i < arr.size();i++){
        cout << arr[i] << " ";
    }
    return 0;
}