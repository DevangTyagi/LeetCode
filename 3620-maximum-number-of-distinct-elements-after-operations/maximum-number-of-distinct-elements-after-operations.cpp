class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
      int dist = 0;
      sort(nums.begin(),nums.end());
      int next_valid = nums[0]-k;
      for(auto &num : nums)  {
        next_valid = max(next_valid , num-k);
        if(next_valid <= num+k){
            dist++;
            next_valid++;
        }
      }
      return dist;
    }
};