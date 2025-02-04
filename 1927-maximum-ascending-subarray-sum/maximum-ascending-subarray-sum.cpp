class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maxsum = sum;
        if(nums.size()==1)
        return sum;
        for(int i=1;i<nums.size();i++) {
            if(nums[i] > nums[i-1]){
                sum += nums[i];
                maxsum = max(maxsum,sum);
            }
            else
            sum = nums[i];
        }
        return max(maxsum,sum);
    }
};