#include<iostream>
#define MAXSIZE 10
using namespace std;
void swtich_sort(int nums[]){

    for(int i = 0 ;i < MAXSIZE - 1;i++){
        for(int j = i + 1;j < MAXSIZE ;j++ ){
            if(nums[i] >nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

}

int binary_search(int nums[],int n,int x){
    int low = 0;
    int high = n -1;
    while(low <= high){
        int mid = (high - low)/2 +low;
        if(x == nums[mid]) return mid;

        if(nums[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}


int main(){

    int arr[MAXSIZE] = {1,4,4,13,1, 45,78,120,140,169};
    swtich_sort(arr);
    for(int num:arr){
        cout << num << " ";
    }
    cout << endl << "请你输入需要查找的元素";
    int num = 0;
    cin >> num;
    if(binary_search(arr,MAXSIZE,num)){
        cout << "该元素在数组中存在";
    }else cout << "该元素不存在";

    return 0;
}