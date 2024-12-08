class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int k = nums[i];
            ans[i] = nums[(i + k % n + n) % n];
        }
        return ans;
    }
};