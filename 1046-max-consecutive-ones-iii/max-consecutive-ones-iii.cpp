class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int maxlen=INT_MIN;
        int l=0,r=0,zeroes=0;
        int n = nums.size();
        while(r<n)
        {         
           if(nums[r]==0) zeroes++;
           while(zeroes>k){
            if(nums[l]==0)
            {
             zeroes--;
            } 
            l++;
           }  
           if(zeroes<=k){
            maxlen=max(maxlen,r-l+1);
           }      
           r++;   
        }
        return maxlen;
    }
};