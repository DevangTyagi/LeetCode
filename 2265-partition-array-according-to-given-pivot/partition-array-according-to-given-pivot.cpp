class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int count = 0, left = 0;
        for (auto &num : nums) {
            if (num < pivot)
                ans[left++] = num;
            else if (num == pivot)
                count++;
        }
        while (count--)
           ans[left++] = pivot;
        for(auto &num : nums) {
            if(num > pivot)
            ans[left++] = num;
        }
        return ans;
    }
};