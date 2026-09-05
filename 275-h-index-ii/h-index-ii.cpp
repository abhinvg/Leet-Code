class Solution {
public:

    int helper(vector<int>& citations , int mid){
        int low = 0;
        int high = citations.size()-1;
        int ans =-1;
        

        while(low<=high){
            int guess = low + (high-low)/2;
            
            if(citations[guess] < mid){
                low = guess+1;
            }
            else{
                ans = guess;
                high = guess-1;
            }
            
        }
        return ans;


    }
    int hIndex(vector<int>& citation) {
        int low = 0;
        int high = *max_element(citation.begin(),citation.end());
        int n = citation.size();
        int ans = -1;
        

        while(low <= high){
            int mid = low + (high-low)/2;
            int index = helper(citation, mid);

             int count = (index == -1) ? 0 : n - index;

            if(count < mid ){
                high = mid-1;;
            }
            if(count >= mid){
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
};