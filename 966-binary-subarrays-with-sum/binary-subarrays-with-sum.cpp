class Solution {
public:
  int find_no_subarrays(vector<int>& nums, int goal)
  {
    int count=0,sum=0;
        int l=0,r=0;
        if(goal < 0) 
        return 0;
        while(r<nums.size())
        {
         sum += nums[r];
         while(sum > goal)
         {
            sum -= nums[l];
            l++;
         }
         count += (r-l+1);
         r++;
        }
        return count;
  }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {

       int back = find_no_subarrays(nums,goal-1);
       int front = find_no_subarrays(nums,goal);
       return front-back;
    }
};