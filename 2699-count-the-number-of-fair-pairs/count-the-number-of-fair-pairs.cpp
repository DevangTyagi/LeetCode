class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
       long long count=0;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++)
       {
        int lower_idx = lower_bound(begin(nums) + i + 1 , end(nums) , lower-nums[i]) - begin(nums) ;
        int lower_count = lower_idx - i -1;
        int upper_idx = upper_bound(begin(nums) + i + 1 , end(nums) , upper-nums[i]) - begin(nums);
        int upper_count = upper_idx - i -1;

        count += (upper_count - lower_count);
       } 
       return count;
    }
};