class Solution {
public:

    long long helper(vector<int> piles , int speed){
        long long count = 0;
        for(int i=0; i<piles.size() ; i++){
            count += piles[i] / speed;  
            if(piles[i] % speed != 0){
            count++;
        }
        }
        
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = -1;

        while(low<=high){

            int guess = low + (high-low)/2;
            long long count = helper(piles ,guess );

            if(count > h){
                low = guess+1;
            }
            else{
                ans = guess;
                high = guess-1;
            }

        }
        return ans;


        
    }
};