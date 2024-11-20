class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        long long sum = 0;
        long long maxsum = INT_MIN;
        unordered_set<int>st;
        int i=0,j=0;
        while(j < nums.size()){
            while(st.count(nums[j])){  // Shrink window until duplicate is present.
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            sum += nums[j];
            st.insert(nums[j]);
            if(j-i+1 == k){
                maxsum = max(sum,maxsum);
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }   
            ++j;     
        }
         return (maxsum != INT_MIN) ? maxsum : 0;
    }
};