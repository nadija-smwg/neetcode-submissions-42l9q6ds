class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxl = 0, maxr = 0;
        int res = 0;
        
        while (i < j) {
            if (height[i] < height[j]) {
                maxl = max(maxl, height[i]);
                res += maxl - height[i];
                i++;
            } else {
                maxr = max(maxr, height[j]);
                res += maxr - height[j];
                j--;
            }
        }
        return res;
    }
};
