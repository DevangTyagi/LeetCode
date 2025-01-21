class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int maxsum = 0;
        for(int i=0;i<nums.size();i++){
            int start = max(0,i-nums[i]);
            int temp_sum=0;
            for(int j=start;j<=i;j++)
            temp_sum += nums[j];
            maxsum += temp_sum;
        }
        return maxsum;
    }
};