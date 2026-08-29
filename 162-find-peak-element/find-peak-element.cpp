class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low =0;
        int high = nums.size()-2;
        int ans = -1;
        if(nums.size() == 1){
            return 0;
        }

        while(low<=high){
            int mid = low+(high-low)/2;

            if(nums[mid] > nums[mid+1]){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

         if (ans == -1) {
            return nums.size() - 1;
        }

        return ans;
        
    }
};