class Solution {
public:
    int helper(vector<int>nums){
        int low = 0;
        int high = nums.size()-1;
        int ans =-1;

        while(low<=high){
            int guess = low + (high-low)/2;

            if(nums[guess] > nums[nums.size()-1]){
                low = guess + 1;
            }
            else{
                ans = guess;
                high = guess-1;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int high;
        int low;
        int ans = -1;
       if(nums[nums.size()-1] < target){
        low = 0;
        high = helper(nums)-1;

       }
       else{
        low = helper(nums);
        high = nums.size()-1;
       }

       while(low<=high){
        int mid = low + (high - low)/2;

        if(nums[mid] == target){
            ans = mid;
        }
        if(nums[mid] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
       }
    return ans;
       

    }
};