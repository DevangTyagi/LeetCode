class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int k = nums[i];
            if(nums[i] > 0)
            ans[i] = nums[(i + k % n)%n];
            else if(nums[i] < 0)
            ans[i] = nums[(n - abs(k)%n + i)%n];
            else
            ans[i] = 0;
        }
        return ans;
    }
};