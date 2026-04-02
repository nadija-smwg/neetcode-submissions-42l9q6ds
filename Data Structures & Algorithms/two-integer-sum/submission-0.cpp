// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int,int> mp;


//         for (int i = 0; i < nums.size(); i++) {
//             int diff = target - num;
//             if (mp.find(diff)) {
//                 return {mp[diff], i}
//             }
//             mp.insert({nums[i], i})
//         }
//         return {};
//     }
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            if (mp.find(need) != mp.end()) {
                int j = mp[need];
                return {j,i};
            }

            mp[nums[i]] = i;
        }

        return {}; // not needed (guaranteed solution)
    }
};