class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (nums.empty()) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0],nums[1]);
        
        nums.push_back(0);
        for (int i = nums.size()-4; i >= 0; i--) {
            nums[i] = nums[i] + max(nums[i+3],nums[i+2]);
        }
        return max(nums[0],nums[1]);
    }
};
