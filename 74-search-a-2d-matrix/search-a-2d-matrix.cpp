class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mtr, int target) {
        int m = mtr.size();
        int n = mtr[0].size();
        int low = 0;
        int high = m*n-1;

        while(high >= low){
            int mid = low + (high-low)/2;

            int r = mid/n;
            int c = mid%n;

            if(mtr[r][c] == target){
                return true;
            }
            if(mtr[r][c] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
};