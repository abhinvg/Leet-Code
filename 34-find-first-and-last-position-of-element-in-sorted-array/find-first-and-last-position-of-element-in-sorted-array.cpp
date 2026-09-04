class Solution {
public:
    int left(vector<int>&nums,int target){
         int low = 0;
        int high = nums.size()-1;
        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                ans = mid;
                high = mid-1;
                continue;
            }

            if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }

        }
        return ans;
    }


    int right(vector<int>&nums,int target){
         int low = 0;
        int high = nums.size()-1;
        int ans = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                ans = mid;
                low = mid+1;
                continue;
            }

            if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }

        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vec;
        int leftt = left(nums,target);
        int rightt = right(nums,target);
        vec.push_back(leftt);
        vec.push_back(rightt);
        return vec;


    }
};