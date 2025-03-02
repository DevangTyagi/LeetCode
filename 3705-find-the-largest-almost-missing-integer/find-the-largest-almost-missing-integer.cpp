class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (auto& itr : nums)
            mpp[itr]++;
        if (k == 1) {
            int solo_unq = -1;
            for (auto& [key, count] : mpp) {
                if (count == 1)
                    solo_unq = max(key, solo_unq);
            }
            return solo_unq;
        }

        if (k == n)
            return *max_element(nums.begin(), nums.end());

        bool first_unq = (mpp[nums[0]] == 1);
        bool second_unq = (mpp[nums[n - 1]] == 1);

        if (first_unq && second_unq)
            return max(nums[0], nums[n - 1]);
        if (first_unq)
            return nums[0];
        if (second_unq)
            return nums[n - 1];

        return -1;
    }
};