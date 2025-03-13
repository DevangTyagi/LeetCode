class Solution {
public:
    bool solve(vector<int>& nums, vector<vector<int>>& queries, int idx) {
        int n = nums.size();
        vector<int>diff(n,0);
        for (int i = 0; i <= idx; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            int val = queries[i][2];
            diff[left] += val;
            if(right + 1 < n){
                diff[right+1] -= val;
            }           
        }
        int cumsum = 0;
        for(int i=0;i<n;i++) {
            cumsum += diff[i];
            diff[i] = cumsum;
            if(diff[i] < nums[i])
            return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size(), zeroes = 0,ans = -1;
        for (auto itr : nums) {
            if (itr == 0)
                zeroes++;
        }
        if (zeroes == nums.size())
            return 0;
        int l=0,r=n-1;
        while(l <= r) {   // BInary Search
            int mid = l + (r-l)/2;
            if(solve(nums,queries,mid)) {
              ans = mid + 1;
              r = mid -1 ;
            }
            else {
                l = mid + 1;
            }

        }
        return ans;
    }
};