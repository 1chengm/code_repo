#include <iostream>
#include <vector> 
using namespace std;

void insertion(vector<int> & nums){

    for(int i = 1;i < nums.size();i++){
        int base = nums[i];
        int j = i -1;
        while(j>=0 &&nums[j] >base ){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = base;
    }
}

int main (){

    vector<int> arr = {10, 7, 8, 9, 1, 5};
     insertion(arr);
    for(int i = 0;i < arr.size();i++){
        cout << arr[i] << " ";
    }
    return 0;
}