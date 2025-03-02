class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k)
            return -1;
             unordered_map<int, unordered_set<int>> subarrayIndices;

        for (int i = 0; i <= n - k; i++) {
            for (int j = i; j < i + k; j++) {
                subarrayIndices[nums[j]].insert(i);
            }
        }

        int result = -1;
        for (auto& [num, indices] : subarrayIndices) {
            if (indices.size() == 1) {
                result = max(result, num);
            }
        }

        return result;
    }
};