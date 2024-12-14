class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
        int j=0;
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            while(abs(mpp.rbegin()->first - mpp.begin()->first) > 2){
                mpp[nums[j]] -= 1;
                if(mpp[nums[j]]==0)
                mpp.erase(nums[j]);
                j++;
            }
            count += (i-j+1);
        }
        return count;
    }
};