class Solution {
public:
    int Find_Subarrays(vector<int>& nums, int k)
    {
      int l=0,r=0,count=0;
      unordered_map<int,int>mpp;
      if(k<1) 
      return 0;
      while(r<nums.size())
      {
        mpp[nums[r]]++;
        while(mpp.size()>k)
        {
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0)
            mpp.erase(nums[l]);
            l++;
        }
        if(mpp.size()<=k)
        count += r-l+1;
        r++;
      }  
      return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
      int f_unique = Find_Subarrays(nums,k);
      int b_unique = Find_Subarrays(nums,k-1);
      return f_unique - b_unique;
    }
};