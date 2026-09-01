class Solution {
public:

    long long helper(vector<int> piles , int h,int speed){
        long long count = 0;
        for(int i =0;i<piles.size();i++){
            count += piles[i]/speed;
            if(piles[i] % speed != 0){
                count++;
            }
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
          int high = *max_element(piles.begin(), piles.end());

        int ans =-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(helper(piles,h,mid) > h){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};