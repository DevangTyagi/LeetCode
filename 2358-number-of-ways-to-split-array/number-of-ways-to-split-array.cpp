class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(), 0LL);
        int count = 0;
        long long first_sum = 0;
        for(int i = 0 ; i < nums.size()-1 ; i++){
         first_sum += nums[i];
         if(first_sum >= sum - first_sum)
         count++;
        }
        return count;
    }
};