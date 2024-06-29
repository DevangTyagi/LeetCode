class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        // initial index will give the final result
      int t=nums.size();
      while(t--)
      {
        swap(nums[0],nums[nums[0]]);
      }  
      return nums[0];
    }
};