class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix_sum = {nums.front()};
        vector<int> suffix_sum(nums.size(),nums.back());
        vector<int> result;
        int p=1,s=1;
        
        for (int i=1; i<size; i++) {
            prefix_sum.push_back(prefix_sum[i-1]*nums[i]);
            suffix_sum[size-i-1]=suffix_sum[size-i]*nums[size-i-1];
        }
        for(int i=0;i<size; i++) {
            if (i==0){
                result.push_back(suffix_sum[1]);
            }else if(i==size-1){
                result.push_back(prefix_sum[size-2]);
            }else{
                result.push_back(prefix_sum[i-1] * suffix_sum[i+1]);
            }
        }
        return result;
    }
};
