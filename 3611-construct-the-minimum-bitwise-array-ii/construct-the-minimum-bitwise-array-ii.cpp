class Solution {
public:
  int solve(int num) {
        if (num % 2 == 0) {
            return -1;
        }
        int mini = INT_MAX;
        for (int i = 0; i < 32; ++i) {
            if (num & (1 << i)) {
                int modifiedNum = num & ~(1 << i);
                if ((modifiedNum | (modifiedNum + 1)) == num) {
                    mini = min(mini, modifiedNum);
                }
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
         vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(solve(nums[i]));
        }
        return ans;
    }
};