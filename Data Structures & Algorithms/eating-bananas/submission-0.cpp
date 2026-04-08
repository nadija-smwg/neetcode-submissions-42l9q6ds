class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int j = *max_element(piles.begin(),piles.end());
        int i = 1;
        int res = j;
        

        while (i<=j){
            int mid = (i + j) / 2 ; 

            long long totalTime = 0;
            for (int p : piles){
                totalTime += ceil(static_cast<double>(p)/mid);
            }
            if (totalTime <= h) {
                res = mid;
                j = mid - 1;
            }
            else{
                i = mid+1;
            }
        }
        return res;
        
    }
};
 