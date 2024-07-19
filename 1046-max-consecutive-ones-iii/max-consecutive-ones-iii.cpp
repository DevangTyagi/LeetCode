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
           if(zeroes>k){
            if(nums[l]==0)
            {
             zeroes--;
            } 
            l++;
           }  
           if(zeroes<=k){    //Condition <= is is used instesd of == because it will include the substring which may have length of larger than all but use less zeroes than k
            maxlen=max(maxlen,r-l+1);
           }      
           r++;   
        }
        return maxlen;
    }
};