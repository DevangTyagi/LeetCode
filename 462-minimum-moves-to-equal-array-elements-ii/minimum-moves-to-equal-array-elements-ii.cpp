class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int med_idx = nums.size()/2;
        for(auto itr : nums) {
        ans += abs(nums[med_idx] - itr);
    }
    return ans;
    }
};