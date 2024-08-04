class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        int sum=0;
        int mod = 1e9+7;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum = (sum + nums[j])%mod;
                ans.push_back(sum);
            }
        }
        sort(ans.begin(),ans.end());
        int maxsum = 0;
        for(int i=left-1;i<right;i++)
        {
           maxsum = (maxsum+ans[i])%mod;
        }
        return maxsum;
    }
};