class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int j= c-1, i=0; 

        while(i<r && j>=0) {
            
            if (matrix[i][j] > target){
                j--;
            }else if (matrix[i][j] < target){
                i++;
            }else{
                return true;
            }
        }
        return false;  
    }
};
