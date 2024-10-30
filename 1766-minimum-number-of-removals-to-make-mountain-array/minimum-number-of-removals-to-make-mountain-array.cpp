class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) 
    {
        vector<int>LIS(nums.size(),1);
        vector<int>LDS(nums.size(),1);

      int ans = INT_MAX;
      //LIS
      for(int i=0;i<nums.size();i++){
        for(int j=i-1;j>=0;j--){
            if(nums[j] < nums[i])
             LIS[i] = max(LIS[i] , LIS[j]+1);  
        }
      }  
      //LDS
      for(int i=nums.size()-1;i>=0;i--){
        for(int j=i+1;j<nums.size();j++){
            if(nums[j] < nums[i])
             LDS[i] = max(LDS[i] , LDS[j]+1);  
        }
      }
      for(int i=0;i<nums.size();i++){
        if(LIS[i]>1 && LDS[i]>1)
        {
         int removal = nums.size()-LIS[i]-LDS[i]+1;
         ans = min(ans,removal);
        }        
      } 
      return ans;
    }
};