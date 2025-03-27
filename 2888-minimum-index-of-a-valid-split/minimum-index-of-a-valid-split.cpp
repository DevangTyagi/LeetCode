class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        int dominant;
        for (auto& itr : nums) {
            freq[itr]++;
             if (2 * freq[itr] > nums.size()) {
                dominant = itr;
            }
        }
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == dominant)
            count++;
            if(2*count > i+1 && 2*(freq[dominant]-count) > (nums.size()-i-1))
            return i;
        }
        return -1;
    }
};