class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j=numbers.size()-1;
        int i=0;
        vector<int> v;
        while(true) {
            if(numbers[i]+numbers[j] > target){
                j--;
            }else if (numbers[i]+numbers[j] < target){
                i++;
            }else{
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
        }
    }
};
