class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long,long long>freq;
        long long count=0;
        for(long long i=0;i<nums.size();i++)
        freq[nums[i]-i]++;
        for(long long j = nums.size()-1; j>0 ; j--) {
        freq[nums[j]-j]--;
        long long pair = (j - freq[nums[j]-j]);
        if(pair > 0)
        count += pair;
        }
        return count;
    }
};