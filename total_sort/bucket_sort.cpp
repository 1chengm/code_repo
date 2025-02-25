//输入数据范围为[0,1),通过k个桶进行映射到[0,k-1);
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
void bucket_sort(vector<float> &nums){
    int k = nums.size() / 2;
    vector<vector<float>> buckets(k); 
    for(float num :nums){
        int i = num * k; 
        buckets[i].push_back(num);
    }
    for(vector<float> &bucket : buckets){
        sort(bucket.begin(),bucket.end());
    }
    int i = 0;
    for(vector<float> &bucket : buckets){
        for(float num : bucket){
            nums[i++] = num;
        }
    }

}


int main(){
    vector<float> arr = {0.1,0.23,0.4,0.5,0.45,0.61,0.7,0.85,0.64,0.98};
    bucket_sort(arr);
    for(auto num :arr){
        cout << num << " ";
    }
    return 0;
}