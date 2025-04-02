class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long max_value = 0;
        
        int max_prefix = nums[0]; // Stores maximum nums[i] seen so far
        vector<int> max_suffix(n, 0);
        
        // Compute max_suffix[k], the maximum nums[k] for k > j
        max_suffix[n-1] = nums[n-1];
        for (int k = n-2; k >= 0; --k) {
            max_suffix[k] = max(max_suffix[k+1], nums[k]);
        }
        
        for (int j = 1; j < n-1; ++j) {
            max_value = max(max_value, (long long)(max_prefix - nums[j]) * max_suffix[j+1]);
            max_prefix = max(max_prefix, nums[j]);
        }
        
        return max_value;
    }
};